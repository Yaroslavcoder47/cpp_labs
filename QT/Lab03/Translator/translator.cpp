#include "translator.h"
#include "ui_translator.h"

Translator::Translator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Translator)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Translator::convert);
}

Translator::~Translator()
{
    delete ui;
}

void Translator::convert()
{
    textEdit1 = ui->lineEdit->text();
    textEdit2 = ui->lineEdit_2->text();
}
