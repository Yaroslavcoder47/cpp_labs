#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setText("Spawn!");
    ui->comboBox->addItem("PushButton");
    ui->comboBox->addItem("Label");
    ui->comboBox->addItem("CheckBox");
    ui->comboBox->addItem("TextEdit");

    ui->spinBox->setRange(0, 5);
    connect(ui->pushButton, &QPushButton::clicked, this, )
}

Widget::~Widget()
{
    delete ui;
}

void Widget::placeWidget(QString widgetName, char count)
{

}