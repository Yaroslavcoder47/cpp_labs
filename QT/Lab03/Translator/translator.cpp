#include "translator.h"
#include "ui_translator.h"
#include <iostream>

Translator::Translator(QWidget *parent) :  QWidget(parent)
{
    connect(this, SIGNAL(setNumber()), this, SLOT(translateNumber()));

    resultLabel = new QLabel("0", this);
    infoLabel1 = new QLabel("Input integer decimal number", this);
    infoLabel2 = new QLabel("Result as binary number", this);
    number = new QLineEdit(this);

    box = new QVBoxLayout();
    box->setContentsMargins(50, 50, 50, 100);
    box->addWidget(infoLabel1);
    box->addWidget(number);
    box->addWidget(infoLabel2);
    box->addWidget(resultLabel);

    setLayout(box);
}

void Translator::translateNumber()
{

}
