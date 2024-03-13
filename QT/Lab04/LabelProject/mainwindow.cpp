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
    if(event == nullptr) // Проверка на nullptr
        return;
    if(event->button() == Qt::LeftButton){
        emit makeLabel();
    }
}

void MainWindow::addLabel()
{
    QLabel *label = new QLabel(this);
    label->setText("Label");
    label->setStyleSheet("background-color: yellow;");
    int posX = QRandomGenerator::global()->bounded(0, this->width() - label->width());
    int posY = QRandomGenerator::global()->bounded(0, this->height() - label->height());
    label->setGeometry(posX, posY, 80, 80);
    labels_.push_back(label);
    label->show();
}
