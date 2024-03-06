#include "translator.h"
#include "ui_translator.h"
#include <iostream>

Translator::Translator(QWidget *parent) :  QWidget(parent)
{
    connect(this, SIGNAL(created()), this, SLOT(onCreated()));

    emit created();

    infoLabel1 = new QLabel("Input integer decimal number", this);
    infoLabel2 = new QLabel("Result as binary number", this);
    number = new QLineEdit(this);

    QVBoxLayout *box = new QVBoxLayout();
    box->setContentsMargins(50, 50, 50, 100);
    box->addWidget(infoLabel1);
    box->addWidget(number);
    box->addWidget(infoLabel2);
    box->addWidget(resultLabel);


    setLayout(box);
}

void Translator::onCreated()
{
    resultLabel = new QLabel("Hello", this);
}
