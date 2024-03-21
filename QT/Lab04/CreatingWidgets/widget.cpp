#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(300, 300);

    QPushButton* btn = new QPushButton("Spawn");
    QComboBox* cmbox = new QComboBox;

    cmbox->addItem("PushButton");
    cmbox->addItem("Label");

    QSpinBox* spn = new QSpinBox;
    spn->setMinimum(0);
    spn->setMaximum(5);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* workWidgetsLayout = new QHBoxLayout();
    QHBoxLayout* widgetAreaLayout = new QHBoxLayout();

    workWidgetsLayout->setAlignment(Qt::AlignTop);

    workWidgetsLayout->addWidget(cmbox);
    workWidgetsLayout->addWidget(spn);
    workWidgetsLayout->addWidget(btn);

    connect(btn, &QPushButton::clicked,this,[cmbox,spn, widgetAreaLayout](){
        if(cmbox->currentText() == "PushButton"){
            for(int i = 0; i < spn->value(); ++i){
                QPushButton* button = new QPushButton();
                button->setText("button");
                widgetAreaLayout->addWidget(button);
            }
        }
        if(cmbox->currentText() == "Label"){
            for(int i = 0; i < spn->value(); ++i){
                QLabel* label = new QLabel();
                label->setText("label");
                widgetAreaLayout->addWidget(label);
            }
        }
    });
    mainLayout->addLayout(workWidgetsLayout);
    mainLayout->addLayout(widgetAreaLayout);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}

