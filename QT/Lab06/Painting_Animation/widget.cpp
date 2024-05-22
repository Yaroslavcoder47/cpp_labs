#include "widget.h"
#include "ui_widget.h"
#include <QPalette>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setFixedSize(1000, 625);
    //setStyleSheet("background-image: url(:/../data/field.jpg);");
    QPalette pal2;
    pal2.setBrush(backgroundRole(),QBrush(QPixmap("../../data/field.jpg")));
    setPalette(pal2);
}

Widget::~Widget()
{
    delete ui;
}
