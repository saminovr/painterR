#ifndef SQUARE_H
#define SQUARE_H

#include "figures.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Square : public Figures
{
    Q_OBJECT
public:
    explicit Square(QPointF point, QObject *parent = nullptr);
    ~Square();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // SQUARE_H
