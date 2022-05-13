#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "figures.h"



class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);

    int radius;
    QColor color;
    int r,g,b;

    bool line;
    bool square;
    bool circle;
    bool triangle;
    bool grid;
    bool radLines;

private:
    QPoint startPoint;

    Figures* tempFigure;

signals:
    void drawGridLines();

private slots:
    void drawGridLinesSlot();



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // PAINTSCENE_H
