#ifndef FIGURES_H
#define FIGURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Figures : public QObject, public QGraphicsItem
{
    Q_OBJECT

    // свойство стартовой точки
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)

    // свойство конечной точки
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)

public:
    explicit Figures(QPointF point, QObject *parent = nullptr);
    ~Figures();

    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка

    void setStartPoint (const QPointF point);
    void setEndPoint (const QPointF point);

    QColor color;
    int radius;


signals:
    void pointChanged();


private:
    QPointF m_startPoint;
    QPointF m_endPoint;



    QRectF boundingRect() const;

public slots:
    void updateFigure();


};



#endif // FIGURES_H
