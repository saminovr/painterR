#include "square.h"

Square::Square(QPointF point, QObject *parent)
    : Figures(point, parent)
{

}

Square::~Square()
{

}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, radius, Qt::SolidLine, Qt::RoundCap));

   QRect rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
              endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
              qAbs(endPoint().x() - startPoint().x()),
              qAbs(endPoint().y() - startPoint().y()));

   painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)



}
