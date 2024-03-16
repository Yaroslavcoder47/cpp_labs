#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{

    resize(400, 200);
    QVBoxLayout* vlayout = new QVBoxLayout();
    QHBoxLayout* hlayout1 = new  QHBoxLayout();
    QHBoxLayout* hlayout2 = new  QHBoxLayout();

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

    connect(chb1, &QCheckBox::stateChanged, this, [=](int state) {buttonDisappear(btn1, state);});
    connect(chb2, &QCheckBox::stateChanged, this, [=](int state) {buttonDisappear(btn2, state);});
    connect(chb3, &QCheckBox::stateChanged, this, [=](int state) {buttonDisappear(btn3, state);});
    connect(chb4, &QCheckBox::stateChanged, this, [=](int state) {buttonDisappear(btn4, state);});
    connect(chb5, &QCheckBox::stateChanged, this, [=](int state) {buttonDisappear(btn5, state);});

    hlayout1->addWidget(btn1);
    hlayout1->addWidget(btn2);
    hlayout1->addWidget(btn3);
    hlayout1->addWidget(btn4);
    hlayout1->addWidget(btn5);

    hlayout2->addWidget(chb1);
    hlayout2->addWidget(chb2);
    hlayout2->addWidget(chb3);
    hlayout2->addWidget(chb4);
    hlayout2->addWidget(chb5);

    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    setLayout(vlayout);
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

void MainWindow::buttonDisappear(QPushButton* btn, int state)
{
    if(state == Qt::Checked){
        btn->hide();
    }
    else{
        btn->show();
    }
}
