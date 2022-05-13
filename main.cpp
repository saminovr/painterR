#include "widget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QIcon icon("://windowIcon_32.png");
    w.setWindowIcon(icon);
    w.setWindowTitle("PaintR©");
    w.show();
    return a.exec();
}
