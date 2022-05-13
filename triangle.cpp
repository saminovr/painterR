#include "triangle.h"

Triangle::Triangle(QPointF point, QObject *parent)
    : Figures(point, parent)
{
    Q_UNUSED(point)
    radius = 1;
}

Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(QPen(color, radius, Qt::SolidLine, Qt::RoundCap));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? +1 : -1)*
                       abs(endPoint().x() - startPoint().x())/2, startPoint().y())
            << QPointF(endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x(), endPoint().y())
            << QPointF(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(), endPoint().y());

    painter->drawPolygon(polygon);




    Q_UNUSED(option)
    Q_UNUSED(widget)



}
