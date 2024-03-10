#include "startbutton.h"
#include "ui_startbutton.h"

StartButton::StartButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartButton)
{
    ui->setupUi(this);

    connect(btn, btn->, this, )

}

StartButton::~StartButton()
{
    delete ui;
    delete btn;
}
