#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QLabel *lbl = new QLabel(this);
        lbl->setText("Label");
        lbl->setStyleSheet("background-color: yellow;");
        lbl->setGeometry(100, 100, 20, 20);
        lbl->show();
    }
}
