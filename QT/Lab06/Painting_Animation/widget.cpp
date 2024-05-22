#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    fox->load(":/data/fox.png");
    setFixedSize(1000, 625);
    //setStyleSheet("background-image: url(:/../data/field.jpg);");
    QPalette pal2;
    pal2.setBrush(backgroundRole(),QBrush(QPixmap("../../data/field.jpg")));
    setPalette(pal2);
    //QPalette pal1;
    //pal1.setBrush(backgroundRole(),QBrush(QPixmap("../../data/fox.png")));
    //fox->setPalette(pal1);
}

Widget::~Widget()
{
    delete ui;
}
