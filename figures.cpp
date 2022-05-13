#include "figures.h"

Figures::Figures(QPointF point, QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    connect(this, &Figures::pointChanged, this, &Figures::updateFigure);



}


Figures::~Figures()
{

}

QPointF Figures::startPoint() const
{
    return m_startPoint;
}

QPointF Figures::endPoint() const
{
    return m_endPoint;
}

void Figures::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figures::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QRectF Figures::boundingRect() const
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                      qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figures::updateFigure()
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                     (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                     qAbs(endPoint().x() - startPoint().x()) + 10,
                     qAbs(endPoint().y() - startPoint().y()) + 10);
}
