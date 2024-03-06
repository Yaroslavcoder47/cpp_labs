#include "translator.h"
#include "ui_translator.h"
#include <iostream>

Translator::Translator(QWidget *parent) : QWidget(parent)
{
   // ui->setupUi(this);
    QLabel *result = new QLabel("jgjthgjtgjtghjtgh", this);
    QLineEdit *number = new QLineEdit(this);
    number->frameSize();

    QVBoxLayout *grid = new QVBoxLayout();
    grid->setContentsMargins(50, 50, 50, 100);
    grid->setSpacing(20);
    std::cout << grid->spacing();
    grid->setAlignment(Qt::AlignHCenter);
    grid->addWidget(number);
    grid->addWidget(result);

    setLayout(grid);

}

