#include "translator.h"
#include "ui_translator.h"

Translator::Translator(QWidget *parent) : QWidget(parent)
{
    QLabel *resultLabel = new QLabel("0", this);
    QLabel *infoLabel1 = new QLabel("Input integer decimal number", this);
    QLabel *infoLabel2 = new QLabel("Result as binary number", this);
    QLineEdit *number = new QLineEdit(this);

    QVBoxLayout *box = new QVBoxLayout();
    box->setContentsMargins(50, 50, 50, 100);
    box->addWidget(infoLabel1);
    box->addWidget(number);
    box->addWidget(infoLabel2);
    box->addWidget(resultLabel);

    //box->setAlignment(Qt::AlignHCenter);

    setLayout(box);
}

