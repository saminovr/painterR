#include "line.h"

Line::Line(QPointF point, QObject *parent)
    : Figures(point, parent)
{
    Q_UNUSED(point)
    radius = 1;
}

Line::~Line()
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(QPen(color, radius, Qt::SolidLine, Qt::RoundCap));

    QLineF line(startPoint().x(), startPoint().y(), endPoint().x(), endPoint().y());

    painter->drawLine(line);

    Q_UNUSED(option)
    Q_UNUSED(widget)



}
