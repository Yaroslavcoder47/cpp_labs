#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QGridLayout* grid = new QGridLayout;
    resize(400, 400);
    buttons.resize(dim);
    check.resize(dim);
    for(size_t i = 0; i < dim; ++i){
        buttons[i].resize(dim);
        check[i].resize(dim);
        for(size_t j = 0; j < dim; ++j){
            buttons[i][j] = new QPushButton;
            check[i][j] = 0;
            buttons[i][j]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            grid->addWidget(buttons[i][j], i, j);
        }
    }
    setLayout(grid);

    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            connect(buttons[i][j], &QPushButton::clicked, [this, i, j, grid](){
                buttons[i][j]->setText(sign[turn]);
                check[i][j] = turn * 2 - 1; // -1 - X; 1 - O
                ++turn;
                turn %= 2;
                if(checkWin().first){
                    QLabel* lbl = new QLabel;
                    lbl->setText(checkWin().second + " Win");
                    grid->addWidget(lbl, dim, 0, dim, -1, Qt::AlignCenter);
                    DisableButtons();
                }
                if(checkDraw()){
                    QLabel* lbl = new QLabel("Draw");
                    grid->addWidget(lbl, dim, 0, dim, -1, Qt::AlignCenter);
                    DisableButtons();
                }
            });
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

QPair<bool, QString> Widget::checkWin()
{
    QPair<bool, QString> result;
    int HorizontalSum = 0;
    int VerticalSum = 0;
    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            HorizontalSum += check[i][j];
        }
        if(abs(HorizontalSum) == 3){
            result.first = true;
            result.second = buttons[i][0]->text();
            return result;
        }
        HorizontalSum = 0;
    }

    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            VerticalSum += check[j][i];
        }
        if(abs(VerticalSum) == 3){
            result.first = true;
            result.second = buttons[dim-1][i]->text();
            return result;
        }
        VerticalSum = 0;
    }

    HorizontalSum = 0;
    VerticalSum = 0;
    // use VerticalSum and HorizontalSum to calculate diagonals
    for(size_t i = 0; i < dim; ++i){
        HorizontalSum += check[i][i];
        if(abs(HorizontalSum) == 3){
            result.first = true;
            result.second = buttons[i][i]->text();
            return result;
        }
    }

    for(size_t i = 0; i < dim; ++i){
        VerticalSum += check[i][dim-i-1];
        if(abs(VerticalSum) == 3){
            result.first = true;
            result.second = buttons[i][dim-i-1]->text();
            return result;
        }
    }

    result.first = false;
    return result;
}

void Widget::DisableButtons()
{
    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            buttons[i][j]->setEnabled(false);
        }
    }
}

bool Widget::checkDraw()
{
    int sum = 0;
    for(size_t i = 0; i < dim; ++i){
        for(size_t j = 0; j < dim; ++j){
            if(check[i][j] == 0){
                return false;
            }
            sum += check[i][j];
        }
    }
    if(abs(sum) == 1){
        return true;
    }
    return false;
}

