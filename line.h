#ifndef LINE_H
#define LINE_H

#include "figures.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Line : public Figures
{
    Q_OBJECT
public:
    explicit Line(QPointF point, QObject *parent = nullptr);
    ~Line();

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // LINE_H
