#include "translator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Translator w;
    w.resize(550, 400);
    w.show();
    return a.exec();
}
