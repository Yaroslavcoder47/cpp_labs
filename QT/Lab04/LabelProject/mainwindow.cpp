#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    connect(this, SIGNAL(makeLabel()), this, SLOT(addLabel()));
}

MainWindow::~MainWindow()
{
    delete ui;
    for(auto it : labels_){
        delete it;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event == nullptr)
        return;
    if(event->button() == Qt::LeftButton){
        emit makeLabel();
    }
}

void MainWindow::addLabel()
{
    QLabel *label = new QLabel(this);
    int count = 0;
    int posX = QRandomGenerator::global()->bounded(0, this->width() - label->width());
    int posY = QRandomGenerator::global()->bounded(0, this->height() - label->height());
    while(checkIntersection(QRect(posX,posY,label->width(),label->height()))){
        ++count;
        posX = QRandomGenerator::global()->bounded(0, this->width() - label->width());
        posY = QRandomGenerator::global()->bounded(0, this->height() - label->height());
        if(count >= 10000){
            return;
        }
    }
    label->move(posX, posY);
    label->setText("Label");
    label->setAlignment(Qt::AlignCenter);
    QString colorStr = "background-color: rgb(%1,%2,%3)";
    label->setStyleSheet(colorStr.arg(std::max(170,rand() % 255)).arg(std::max(170,rand() % 255)).arg(std::max(170,rand() % 255)));
    labels_.push_back(label);
    label->show();
}

bool MainWindow::checkIntersection(QRect a){
    for(size_t i = 0; i < labels_.size();i++){
        if(a.intersects(labels_[i]->geometry())){
            return true;
        }
    }
    return false;
}
