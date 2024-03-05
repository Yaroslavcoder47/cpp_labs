#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "translator.h"
#include "ui_translator.h"

Translator::Translator(QWidget *parent) : QWidget(parent)
{
   // ui->setupUi(this);
    QLabel *result = new QLabel("0", this);
    QLineEdit *number = new QLineEdit(this);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(number, 0, 0);
    grid->addWidget(result, 0, 1);

    setLayout(grid);

}

