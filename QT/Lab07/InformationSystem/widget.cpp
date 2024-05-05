#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    //ui->setupUi(this);
    buildInterface();
}

Widget::~Widget()
{
    delete ui;
}

void deleteLayout(QHBoxLayout* layout)
{
    layout->deleteLater();
    layout->deleteLater();
}

void Widget::buildInterface()
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* vLayout_1 = new QVBoxLayout;
    vLayout_1->setSpacing(20);
    QHBoxLayout* hLayout_1 = new QHBoxLayout;
    QVBoxLayout* vLayout_2 = new QVBoxLayout;

    //формирование левой половины экрана
    QVBoxLayout* leftColumnPanel = new QVBoxLayout;
    QVBoxLayout* rightColumnPanel = new QVBoxLayout;

    QLabel* labelInfo = new QLabel("Тип информации");
    QLabel* labelName = new QLabel("Наименование");
    QLabel* labelAuthor = new QLabel("Автор");
    QLabel* labelPrice = new QLabel("Цена");
    QLabel* labelAditional = new QLabel("Примечание");

    QLineEdit* editInfo = new QLineEdit;
    editInfo->setFixedSize(400, 40);
    QLineEdit* editName = new QLineEdit;
    editName->setFixedSize(400, 40);
    QLineEdit* editAuthor = new QLineEdit;
    editAuthor->setFixedSize(400, 40);
    QLineEdit* editPrice = new QLineEdit;
    editPrice->setFixedSize(400, 40);
    QLineEdit* editAditional = new QLineEdit;
    editAditional->setFixedSize(400, 40);


    leftColumnPanel->addWidget(labelInfo);
    rightColumnPanel->addWidget(editInfo);


    leftColumnPanel->addWidget(labelName);
    rightColumnPanel->addWidget(editName);


    leftColumnPanel->addWidget(labelAuthor);
    rightColumnPanel->addWidget(editAuthor);


    leftColumnPanel->addWidget(labelPrice);
    rightColumnPanel->addWidget(editPrice);

    editAditional->setFixedHeight(50);

    leftColumnPanel->addWidget(labelAditional);
    rightColumnPanel->addWidget(editAditional);

    hLayout_1->setAlignment(Qt::AlignTop);
    vLayout_1->setAlignment(Qt::AlignTop);
    QPushButton* exitButton = new QPushButton("Выйти");
    exitButton->setFixedSize(200, 40);

    hLayout_1->addLayout(leftColumnPanel);
    hLayout_1->addLayout(rightColumnPanel);
    vLayout_1->addLayout(hLayout_1);
    vLayout_1->addWidget(exitButton);


    // формирование правой половины экрана
    vLayout_2->setAlignment(Qt::AlignTop);
    QLineEdit* mainEdit = new QLineEdit();
    mainEdit->setAlignment(Qt::AlignTop);
    mainEdit->setFixedHeight(400);
    vLayout_2->setSpacing(20);

    vLayout_2->addWidget(mainEdit);

    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* openButton = new QPushButton("Открыть");
    QPushButton* sortButton = new QPushButton("Сортировать");
    QPushButton* saveButton = new QPushButton("Сохранить");
    QPushButton* searchButton = new QPushButton("Поиск");
    QPushButton* deleteButton = new QPushButton("Очистить");

    addButton->setFixedSize(200, 40);
    openButton->setFixedSize(200, 40);
    sortButton->setFixedSize(200, 40);
    saveButton->setFixedSize(200, 40);
    searchButton->setFixedSize(200, 40);
    deleteButton->setFixedSize(200, 40);

    vLayout_2->addWidget(addButton);
    vLayout_2->addWidget(openButton);
    vLayout_2->addWidget(sortButton);
    vLayout_2->addWidget(saveButton);
    vLayout_2->addWidget(searchButton);
    vLayout_2->addWidget(deleteButton);

    mainLayout->addLayout(vLayout_1);
    mainLayout->addLayout(vLayout_2);
    setLayout(mainLayout);
}
