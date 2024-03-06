#include "translator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Translator w;
    w.resize(200, 200);
    w.setWindowTitle("Translator");

    w.show();
    return a.exec();
}
