#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{

    resize(400, 200);
    QGridLayout* grid = new QGridLayout;
    QCheckBox* chb1 = new QCheckBox("Box 1");
    QCheckBox* chb2 = new QCheckBox("Box 2");
    QCheckBox* chb3 = new QCheckBox("Box 3");
    QCheckBox* chb4 = new QCheckBox("Box 4");
    QCheckBox* chb5 = new QCheckBox("Box 5");

    QPushButton* btn1 = new QPushButton("Button 1");
    QPushButton* btn2 = new QPushButton("Button 2");
    QPushButton* btn3 = new QPushButton("Button 3");
    QPushButton* btn4 = new QPushButton("Button 4");
    QPushButton* btn5 = new QPushButton("Button 5");

    setButtonParametrs(btn1);
    setButtonParametrs(btn2);
    setButtonParametrs(btn3);
    setButtonParametrs(btn4);
    setButtonParametrs(btn5);

    connect(chb1, &QCheckBox::stateChanged, this, SLOT(buttonDisappear(QPushButton* btn)));



    grid->addWidget(btn1, 0, 0);
    grid->addWidget(btn2, 0, 1);
    grid->addWidget(btn3, 0, 2);
    grid->addWidget(btn4, 0, 3);
    grid->addWidget(btn5, 0, 4);

    grid->addWidget(chb1, 1, 0);
    grid->addWidget(chb2, 1, 1);
    grid->addWidget(chb3, 1, 2);
    grid->addWidget(chb4, 1, 3);
    grid->addWidget(chb5, 1, 4);

    setLayout(grid);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setButtonParametrs(QPushButton* btn)
{
    btn->setFixedSize(70, 30);
    btn->setStyleSheet("QPushButton { text-align: center; background-color: rgb(150, 242, 230)}");
}

void MainWindow::buttonDisappear(QPushButton &btn)
{
    btn.hide();
}
