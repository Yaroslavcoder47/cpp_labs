#include "startbutton.h"
#include "ui_startbutton.h"

StartButton::StartButton(QWidget *parent) : QWidget(parent), ui(new Ui::StartButton)
{
    ui->setupUi(this);
    btn = new QPushButton("Click me!", this);
    btn->setGeometry(100, 100, 80, 80);
    connect(btn, &QPushButton::clicked, this, StartButton::changeButtonColor);
}
StartButton::~StartButton()
{
    delete ui;
    delete btn;
}

void StartButton::changeButtonColor()
{
    btn->setStyleSheet("background-color: red;");
}
