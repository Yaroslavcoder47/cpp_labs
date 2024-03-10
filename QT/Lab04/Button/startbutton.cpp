#include "startbutton.h"
#include "ui_startbutton.h"

StartButton::StartButton(QWidget *parent) : QWidget(parent), ui(new Ui::StartButton)
{
    ui->setupUi(this);
    btn = new Button(QString("Click me!"), this);
    //btn = new QPushButton("Click me!", this);
    btn->setGeometry(100, 100, 80, 80);
    //connect(btn, &QPushButton::clicked, this, StartButton::changeButtonColor);

}
StartButton::~StartButton()
{
    delete ui;
    delete btn;
}

StartButton::Button::Button(const QString &text, QWidget *parent) : QPushButton(text, parent){}

void StartButton::changeButtonColor()
{
    btn->setStyleSheet("background-color: red;");
}

void StartButton::Button::enterEvent(QEvent *event) {
    Q_UNUSED(event);
    // Генерация новых случайных координат для кнопки
    setGeometry(0, 0, 80, 80);
}
