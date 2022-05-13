#include "circle.h"

Circle::Circle(QPointF point, QObject *parent)
    : Figures(point, parent)
{
    Q_UNUSED(point)
    radius = 1;
}

Circle::~Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(QPen(color, radius, Qt::SolidLine, Qt::RoundCap));

    QRect rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
               endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
               qAbs(endPoint().x() - startPoint().x()),
               qAbs(endPoint().y() - startPoint().y()));
    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)



}
