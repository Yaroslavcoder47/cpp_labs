#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Information Application");
    w.setFixedSize(1600, 950);
    w.show();
    return a.exec();
}
