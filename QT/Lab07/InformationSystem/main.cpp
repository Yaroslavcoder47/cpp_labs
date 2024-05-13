#include "widget.h"

#include <QApplication>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(1200, 800);
    w.show();
    return a.exec();
}
