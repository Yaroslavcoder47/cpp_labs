#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QProgressBar>
#include <QSPinBox>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QWidget *centralWidget = new QWidget();
    QWidget *centralWidgetTopPart = new QWidget(centralWidget);
    QWidget *centralWidgetBotPart = new QWidget(centralWidget);
    QVBoxLayout *centralWidgetLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *centralWidgetTopPartLayout = new QHBoxLayout(centralWidgetTopPart);
    QHBoxLayout *centralWidgetBotPartLayout = new QHBoxLayout(centralWidgetBotPart);

    QSpinBox *countOfClicks = new QSpinBox(centralWidgetBotPart);
    countOfClicks->setMaximum(100);
    countOfClicks->setMinimum(1);
    countOfClicks->setFixedSize(90,40);
    centralWidgetBotPartLayout->addWidget(countOfClicks,Qt::AlignBottom);

    QPushButton *click = new QPushButton(centralWidgetBotPart);
    click->setText("Click");
    click->setFixedSize(90,40);
    centralWidgetBotPartLayout->addWidget(click,Qt::AlignBottom);

    QProgressBar *progress = new QProgressBar(centralWidgetTopPart);
    progress->setValue(0);
    centralWidgetTopPartLayout->addWidget(progress);

    connect(click,&QPushButton::clicked,this,[progress,countOfClicks](){
        countOfClicks->setEnabled(false);
        progress->setMaximum(countOfClicks->value());
        progress->setValue(progress->value() + 1);
        if(progress->value() == countOfClicks->value()){
            QCoreApplication::exit();
        }
    });

    centralWidgetLayout->addWidget(centralWidgetTopPart);
    centralWidgetLayout->addWidget(centralWidgetBotPart);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
