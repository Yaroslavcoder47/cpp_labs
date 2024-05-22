#include "widget.h"
#include "ui_widget.h"
#include <QRect>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget), fox("../../data/fox.png") {
    ui->setupUi(this);
    setFixedSize(1000, 625);

    QPalette palBackGround;
    palBackGround.setBrush(backgroundRole(),QBrush(QPixmap("../../data/field.jpg")));
    setPalette(palBackGround);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(200, 200, fox);
}
