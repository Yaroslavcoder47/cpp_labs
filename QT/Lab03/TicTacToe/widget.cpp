#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QGridLayout* grid = new QGridLayout;
    resize(400, 400);
    buttons.resize(dim);
    for(size_t i = 0; i < dim; ++i){
        buttons[i].resize(dim);
        for(size_t j = 0; j < dim; ++j){
            buttons[i][j] = new QPushButton;
            buttons[i][j]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            grid->addWidget(buttons[i][j], i, j);
        }
    }
    setLayout(grid);

    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            connect(buttons[i][j], &QPushButton::clicked, [this, i, j](){
                buttons[i][j]->setText(sign[turn]);
            });
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

