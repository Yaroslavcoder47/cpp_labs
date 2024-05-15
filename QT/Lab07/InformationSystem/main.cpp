#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(1600, 800);
    w.show();
    return a.exec();
}
