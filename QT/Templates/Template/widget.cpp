#include "widget.h"
#include <QDebug>
#include <QButtonGroup>
#include <QLayout>
#include <QScrollBar>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPushButton* button = new QPushButton(QIcon(":/button_icon.png"), "My button", this);
    button->setFixedSize(200, 200);
    connect(button, &QPushButton::pressed, [button]() {
        button->setText("Button is clicked");
    });

    connect(button, &QPushButton::released, [button]() {
        button->setText("My button");
    });


    QPushButton* button1 = new QPushButton("F",this);
   // button1->setFixedSize(200, 40);
    button1->move(200, 400);
    connect(button1, &QPushButton::clicked, [button1](){
        button1->setText("Button 1 clicked");
    });



}

Widget::~Widget() {}

/// Button class

    // QPushButton* button = new QPushButton(QIcon(":/button_icon.png"), "My button", this);
    // button->setFixedSize(200, 200);
    // connect(button, &QPushButton::pressed, [button]() {
    //     button->setText("Button is clicked");
    // });

    // connect(button, &QPushButton::released, [button]() {
    //     button->setText("My button");
    // });


/// Label class

    // QLabel* label1 = new QLabel("My label 1", parent);
    // label1->setStyleSheet("font-size : 20px; color : red;");
    // label1->setMargin(100);

    // QLabel* label2 = new QLabel(parent);
    // label2->setText("My label 2");
    // label2->setBaseSize(20, 50);
    // label2->setMargin(20);
    // label2->setFrameStyle(QFrame::Box);
    // label2->setLineWidth(5);

/// CheckBox class

    // QCheckBox* box = new QCheckBox("Check box", this);
    // box->move(100, 100);
    // box->resize(200, 20);
    // connect(box, &QCheckBox::stateChanged, [box](){
    //     if(box->isChecked()){
    //         box->setText("Is checked");
    //     }
    //     else{
    //         box->setText("Is not checked");
    //     }
    // });

/// RadioButton class

    // QRadioButton* radio1 = new QRadioButton("Radio Button 1", this);
    // QRadioButton* radio2 = new QRadioButton("Radio Button 2", this);
    // radio1->move(100, 200);
    // radio2->move(100, 300);
    // radio1->resize(300, 20);
    // radio2->resize(300, 20);

    // connect(radio1, &QRadioButton::toggled, [radio1](){
    //     if(radio1->isChecked()){
    //         radio1->setText("Radio Button 1 is checked");
    //     }
    //     else{
    //         radio1->setText("Radio Button 1");
    //     }

    // });

    // connect(radio2, &QRadioButton::toggled, [radio2](){
    //     if(radio2->isChecked()){
    //         radio2->setText("Radio Button 2 is checked");
    //     }
    //     else{
    //         radio2->setText("Radio Button 2");
    //     }

    // });


/// GroupBox class

    // QGroupBox* group = new QGroupBox("My Box", this);
    // group->move(200, 200);
    // group->resize(300, 300);
    // QVBoxLayout* layout = new QVBoxLayout(group);
    // QPushButton* pbutton = new QPushButton("Push", this);
    // QRadioButton* rbutton1 = new QRadioButton("Radio 1", this);
    // QRadioButton* rbutton2 = new QRadioButton("Radio 2", this);
    // QRadioButton* rbutton3 = new QRadioButton("Radio 3", this);
    // layout->addWidget(pbutton);
    // layout->addWidget(rbutton1);
    // layout->addWidget(rbutton2);
    // layout->addWidget(rbutton3);


/// Slider class

    // QGroupBox* box1 = new QGroupBox("SLider 1", this);
    // QGroupBox* box2 = new QGroupBox("SLider 2", this);
    // box1->resize(220, 90);
    // box2->resize(80, 220);

    // QLabel* label1 = new QLabel("0", this);
    // QLabel* label2 = new QLabel("0", this);
    // QVBoxLayout* layout1 = new QVBoxLayout(box1);
    // QVBoxLayout* layout2 = new QVBoxLayout(box2);

    // QSlider* slider1 = new QSlider(Qt::Horizontal, this);
    // slider1->setMaximum(300);
    // slider1->resize(200, 50);
    // layout1->addWidget(slider1);
    // layout1->addWidget(label1);
    // box1->move(100, 50);

    // QSlider* slider2 = new QSlider(Qt::Vertical, this);
    // slider2->setMaximum(300);
    // slider2->resize(50, 200);
    // layout2->addWidget(slider2);
    // layout2->addWidget(label2);
    // box2->move(200, 200);

    // connect(slider1, &QSlider::valueChanged, [label1, slider1](){
    //     label1->setText(QString::number(slider1->value()));
    // });

    // connect(slider2, &QSlider::valueChanged, [label2, slider2](){
    //     label2->setText(QString::number(slider2->value()));
    // });
