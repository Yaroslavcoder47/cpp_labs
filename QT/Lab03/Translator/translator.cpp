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
    comboBoxText1 = ui->comboBox->currentText();
    comboBoxText2 = ui->comboBox_2->currentText();

    int baseInitial = comboBoxText1.toInt();
    int baseResult = comboBoxText2.toInt();

    bool isOk;
    QString input = ui->lineEdit->text();
    long num = input.toLong(&isOk, baseInitial);

    ui->lineEdit_2->setText(QString::number(num, baseResult));
}
