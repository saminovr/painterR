#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figures.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Triangle : public Figures
{
    Q_OBJECT
public:
    explicit Triangle(QPointF point, QObject *parent = nullptr);
    ~Triangle();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // TRIANGLE_H
