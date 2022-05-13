#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>

#include "paintscene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    PaintScene* scene;




protected:


signals:


private slots:

    void on_widthSlider_valueChanged();

    void on_setColorButton_clicked();
    void on_redButton_clicked();
    void on_orangeButton_clicked();
    void on_yellowButton_clicked();
    void on_greenButton_clicked();
    void on_blueButton_clicked();
    void on_darkBlueButton_clicked();
    void on_purpleButton_clicked();
    void on_blackButton_clicked();
    void on_whiteButton_clicked();
    void on_clearFieldButton_clicked();
    void on_setLineButton_toggled(bool checked);
    void on_setSquareButton_toggled(bool checked);
    void on_setCircleButton_toggled(bool checked);
    void on_setTriangleButton_toggled(bool checked);
    void on_setGridButton_toggled(bool checked);
    void on_saveButton_clicked();
    void on_openFileButton_clicked();
    void on_setRadLinesButton_toggled(bool checked);
};
#endif // WIDGET_H
