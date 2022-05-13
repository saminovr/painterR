#include "paintscene.h"
#include "line.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"



PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene{parent}
{
    radius = 1;
    r = 0;
    g = 0;
    b = 0;
    line = false;


    connect(this, SIGNAL(drawGridLines()), this, SLOT(drawGridLinesSlot()));

}

void PaintScene::drawGridLinesSlot()
{
    QColor gridColor(128, 128, 128, 255*grid); // если grid = true, то сетка серая(т.е она есть)

    for (int i=1; i<57; i++)
    {
        addLine(0, 10*i, 800, 10*i, QPen(gridColor, 1));
    }
    for (int i=1; i<79; i++)
    {
        addLine(10*i, 0, 10*i, 570, QPen(gridColor, 1));
    }



}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ((!line)&&(!square)&&(!circle)&&(!triangle)&&(!radLines))
    {
        color.setRgb(r,g,b);
        addEllipse(event->scenePos().x()-(radius/2), event->scenePos().y()-(radius/2), radius, radius, QPen(Qt::NoPen), QBrush(color));

    }
    if ((line)&&(event->button()==Qt::LeftButton))
    {
        Line* item = new Line(event->scenePos());
        item->color.setRgb(r,g,b);
        item->radius = radius;
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(item);

    }
    if ((square)&&(event->button()==Qt::LeftButton))
    {
        Square* item = new Square(event->scenePos());
        item->color.setRgb(r,g,b);
        item->radius = radius;
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(item);

    }
    if ((circle)&&(event->button()==Qt::LeftButton))
    {
        Circle* item = new Circle(event->scenePos());
        item->color.setRgb(r,g,b);
        item->radius = radius;
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(item);
    }
    if ((triangle)&&(event->button()==Qt::LeftButton))
    {
        Triangle* item = new Triangle(event->scenePos());
        item->color.setRgb(r,g,b);
        item->radius = radius;
        item->setPos(event->pos());
        tempFigure = item;
        this->addItem(item);
    }
    if (event->button()==Qt::RightButton)
    {
        removeItem(tempFigure);
    }

    startPoint.setX(event->scenePos().x());
    startPoint.setY(event->scenePos().y());
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (radLines)
    {
        color.setRgb(r,g,b);
        addLine(startPoint.x(), startPoint.y(), event->scenePos().x(), event->scenePos().y(),
                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
    }
    else
    {
        if ((!line)&&(!square)&&(!circle)&&(!triangle))
        {
            color.setRgb(r,g,b);
            addLine(event->lastScenePos().x(), event->lastScenePos().y(), event->scenePos().x(), event->scenePos().y(),
                    QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
        }
        else
        {
            tempFigure->setEndPoint(event->scenePos());

            this->update(QRectF(0,0,this->width(), this->height()));
        }
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (radLines)
    {
        color.setRgb(r,g,b);
        addLine(startPoint.x(), startPoint.y(), event->scenePos().x(), event->scenePos().y(),
                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
    }

}









































//void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (line)
//    {
//        color.setRgb(r,g,b);
//        addLine(startPoint.x(), startPoint.y(), event->scenePos().x(), event->scenePos().y(),
//                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
//    }


//}





































//////////////// УЗОРЫ ///////////////////////

//void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (!line)
//    {
//        color.setRgb(r,g,b);
//        addEllipse(event->scenePos().x(), event->scenePos().y(), radius, radius, QPen(Qt::NoPen), QBrush(color));

//    }
//    startPoint.setX(event->scenePos().x());
//    startPoint.setY(event->scenePos().y());
//}

//void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (!line)
//    {
//        color.setRgb(r,g,b);
//        addLine(event->lastScenePos().x(), event->lastScenePos().y(), event->scenePos().x(), event->scenePos().y(),
//                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
//    }
//    else if (line)
//    {
//        color.setRgb(r,g,b);
//        addLine(startPoint.x(), startPoint.y(), event->scenePos().x(), event->scenePos().y(),
//                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
//    }


//}

//void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (line)
//    {
//        color.setRgb(r,g,b);
//        addLine(startPoint.x(), startPoint.y(), event->scenePos().x(), event->scenePos().y(),
//                QPen(QBrush(color), radius, Qt::SolidLine, Qt::RoundCap));
//    }

//}

