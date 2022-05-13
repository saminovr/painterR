#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    scene = new PaintScene;
    scene->setBackgroundBrush(QBrush(Qt::white));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);




    scene->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height()-5);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_widthSlider_valueChanged()
{
    scene->radius = ui->widthSlider->value();
    ui->sliderNumberLabel->setText(QString::number(ui->widthSlider->value()));
}

void Widget::on_setColorButton_clicked()

{
    scene->r = ui->redSpin->value();
    scene->g = ui->greenSpin->value();
    scene->b = ui->blueSpin->value();
}


void Widget::on_redButton_clicked()
{
    ui->redSpin->setValue(255);
    ui->greenSpin->setValue(0);
    ui->blueSpin->setValue(0);
    on_setColorButton_clicked();
}


void Widget::on_orangeButton_clicked()
{
    ui->redSpin->setValue(255);
    ui->greenSpin->setValue(127);
    ui->blueSpin->setValue(0);
    on_setColorButton_clicked();
}


void Widget::on_yellowButton_clicked()
{
    ui->redSpin->setValue(255);
    ui->greenSpin->setValue(255);
    ui->blueSpin->setValue(0);
    on_setColorButton_clicked();
}


void Widget::on_greenButton_clicked()
{
    ui->redSpin->setValue(0);
    ui->greenSpin->setValue(255);
    ui->blueSpin->setValue(0);
    on_setColorButton_clicked();
}


void Widget::on_blueButton_clicked()
{
    ui->redSpin->setValue(0);
    ui->greenSpin->setValue(0);
    ui->blueSpin->setValue(255);
    on_setColorButton_clicked();
}


void Widget::on_darkBlueButton_clicked()
{
    ui->redSpin->setValue(75);
    ui->greenSpin->setValue(0);
    ui->blueSpin->setValue(130);
    on_setColorButton_clicked();
}


void Widget::on_purpleButton_clicked()
{
    ui->redSpin->setValue(143);
    ui->greenSpin->setValue(0);
    ui->blueSpin->setValue(255);
    on_setColorButton_clicked();
}

void Widget::on_blackButton_clicked()
{
    ui->redSpin->setValue(0);
    ui->greenSpin->setValue(0);
    ui->blueSpin->setValue(0);
    on_setColorButton_clicked();
}


void Widget::on_whiteButton_clicked()
{
    ui->redSpin->setValue(255);
    ui->greenSpin->setValue(255);
    ui->blueSpin->setValue(255);
    on_setColorButton_clicked();
}


void Widget::on_clearFieldButton_clicked()
{
    scene->clear();
}




void Widget::on_setLineButton_toggled(bool checked)
{
    if(checked)
    {
        scene->line = true;
        scene->square = false;
        scene->circle = false;
        scene->triangle = false;
        ui->setSquareButton->setChecked(false);
        ui->setCircleButton->setChecked(false);
        ui->setTriangleButton->setChecked(false);
        ui->setRadLinesButton->setChecked(false);
    }
    else if(!checked)
    {
        scene->line = false;
    }
}


void Widget::on_setSquareButton_toggled(bool checked)
{
    if(checked)
    {
        scene->square = true;
        scene->line = false;
        scene->triangle = false;
        scene->circle = false;
        ui->setLineButton->setChecked(false);
        ui->setCircleButton->setChecked(false);
        ui->setTriangleButton->setChecked(false);
        ui->setRadLinesButton->setChecked(false);
    }
    else if (!checked)
    {
        scene->square = false;
    }
}


void Widget::on_setCircleButton_toggled(bool checked)
{
    if (checked)
    {
        scene->circle = true;
        scene->line = false;
        scene->square = false;
        scene->triangle = false;
        ui->setLineButton->setChecked(false);
        ui->setSquareButton->setChecked(false);
        ui->setTriangleButton->setChecked(false);
        ui->setRadLinesButton->setChecked(false);
    }
    else if (!checked)
    {
        scene->circle = false;
    }
}


void Widget::on_setTriangleButton_toggled(bool checked)
{
    if (checked)
    {
        scene->triangle = true;
        scene->line = false;
        scene->square = false;
        scene->circle = false;
        ui->setLineButton->setChecked(false);
        ui->setSquareButton->setChecked(false);
        ui->setCircleButton->setChecked(false);
        ui->setRadLinesButton->setChecked(false);
    }
    else if (!checked)
    {
        scene->triangle = false;
    }
}


void Widget::on_setGridButton_toggled(bool checked)
{
    scene->grid = checked;
    //emit scene->drawGridLines();
}


void Widget::on_saveButton_clicked()
{
    QString newPath = QFileDialog::getSaveFileName(this, "Выберите файл", "C://", "Изображения (*.jpg)");

    QPixmap pixmap(scene->width(), scene->height());

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter);
    pixmap.save(newPath);
}


void Widget::on_openFileButton_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this, "Выберите файл", "C://", "Изображения (*.jpg)");
    scene->addPixmap(QPixmap(newPath));
}


void Widget::on_setRadLinesButton_toggled(bool checked)
{
    if (checked)
    {
        scene->radLines = true;
        scene->triangle = false;
        scene->line = false;
        scene->square = false;
        scene->circle = false;
        ui->setLineButton->setChecked(false);
        ui->setSquareButton->setChecked(false);
        ui->setCircleButton->setChecked(false);
        ui->setTriangleButton->setChecked(false);
    }
    else if (!checked)
    {
        scene->radLines = false;
    }
}

