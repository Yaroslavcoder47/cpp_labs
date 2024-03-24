#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    resize(400, 400);

    QPushButton* button = new QPushButton("Button");
    button->setParent(this);
    button->setFixedSize(50,30);

    QSlider* verticalSlider = new QSlider(Qt::Vertical);
    QSlider* horizontalSlider = new QSlider(Qt::Horizontal);

    horizontalSlider->setMaximum(width());
    verticalSlider->setMaximum(height());
    verticalSlider->setValue(height());

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* vSliderLayout = new QHBoxLayout;
    QHBoxLayout* hSliderLayout = new QHBoxLayout;
    vSliderLayout->setAlignment(Qt::AlignLeft);
    button->move(horizontalSlider->sliderPosition(), height() - verticalSlider->sliderPosition());

    hSliderLayout->addWidget(horizontalSlider);
    vSliderLayout->addWidget(verticalSlider);


    mainLayout->addLayout(hSliderLayout);
    mainLayout->addLayout(vSliderLayout);

    setLayout(mainLayout);

    connect(verticalSlider, &QSlider::valueChanged,
            [button, verticalSlider, this]() { button->move(button->pos().x(), height() - verticalSlider->sliderPosition());
            });

    connect(horizontalSlider, &QSlider::valueChanged,
            [button, horizontalSlider]() { button->move(horizontalSlider->sliderPosition(), button->pos().y());
            });
}

Widget::~Widget()
{
    delete ui;
}
