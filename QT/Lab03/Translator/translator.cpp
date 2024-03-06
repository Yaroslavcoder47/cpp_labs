#include "translator.h"
#include "ui_translator.h"

Translator::Translator(QWidget *parent) : QWidget(parent)
{
   // ui->setupUi(this);
    QLabel *result = new QLabel("jgjthgjtgjtghjtgh", this);
    QLineEdit *number = new QLineEdit(this);
    number->frameSize();

    QVBoxLayout *grid = new QVBoxLayout();
    grid->addWidget(number);
    grid->addWidget(result);

    setLayout(grid);

}

