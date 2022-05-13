#ifndef CIRCLE_H
#define CIRCLE_H

#include "figures.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Circle : public Figures
{
    Q_OBJECT
public:
    explicit Circle(QPointF point, QObject *parent = nullptr);
    ~Circle();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // CIRCLE_H
