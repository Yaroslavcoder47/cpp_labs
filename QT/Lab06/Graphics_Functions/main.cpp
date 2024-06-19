#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Graphics");
    w.setWindowIcon(QIcon(":/mainIcon/image/icon.png"));
    w.setFixedSize(1200, 800);
    w.show();
    return a.exec();
}
