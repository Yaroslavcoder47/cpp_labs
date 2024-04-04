#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int width = width();
    int height = heigth();
    dots_ = qPow(2, qCeil(std::log2f(qMax(width, height) - 1))) + 1;
    plazma_.resize(dots_);
    for(auto& item : plazma_){
        item.resize(dots_);
        for(auto& item1 : item){
            item1 = nullptr;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDotsColor()
{
    plazma_[0][0] = QColor(Qt::red);
    plazma_[dots_ - 1][0] = QColor(Qt::green);
    plazma_[0][dots_ - 1] = QColor(Qt::blue);
    plazma_[dots_ - 1][dots_ - 1] = QColor(Qt::yellow);
}
