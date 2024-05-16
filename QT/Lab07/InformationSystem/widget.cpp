#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    buildInterface();
    connect(exitButton, &QPushButton::clicked, this, QApplication::quit);
    connect(openButton, &QPushButton::clicked, this, &Widget::createArrayObjects);
    connect(deleteButton, &QPushButton::clicked, this, &Widget::clearMainEdit);
    connect(addButton, &QPushButton::clicked, this, &Widget::addElement);
}

void deleteLayout(QHBoxLayout* layout)
{
    layout->deleteLater();
    layout->deleteLater();
}

void Widget::printToMainEdit(QJsonArray& units)
{
    // форматирование текста на вывод
    QString text;
    for(const QJsonValue &val : units){
        text += QString("Type: %1\nName: %2\nAuthor: %3\nPrice: %4\nAdition: %5\n\n")
                    .arg(val["Type"].toString().leftJustified(maxTypeWidth, ' '))
                    .arg(val["Name"].toString().leftJustified(maxNameWidth, ' '))
                    .arg(val["Author"].toString().leftJustified(maxAuthorWidth, ' '))
                    .arg(val["Price"].toString().leftJustified(maxPriceWidth, ' '))
                    .arg(val["Adition"].toString().leftJustified(maxAditionWidth, ' '));

    }
    mainEdit->appendPlainText(text);
}

void Widget::printToMainEdit()
{
    QString text;
    text += QString("Type: %1\nName: %2\nAuthor: %3\nPrice: %4\nAdition: %5\n\n")
                .arg(objects[objects.size()-1].type.leftJustified(maxTypeWidth, ' '))
                .arg(objects[objects.size()-1].name.leftJustified(maxNameWidth, ' '))
                .arg(objects[objects.size()-1].author.leftJustified(maxAuthorWidth, ' '))
                .arg(objects[objects.size()-1].price.leftJustified(maxPriceWidth, ' '))
                .arg(objects[objects.size()-1].adition.leftJustified(maxAditionWidth, ' '));
    mainEdit->appendPlainText(text);
}

void Widget::clearMainEdit()
{
    mainEdit->clear();
}

void Widget::buildInterface()
{
    //главный слой для размещения
    QHBoxLayout* mainLayout = new QHBoxLayout;

    //слои второго уровня для размещения объектов
    QVBoxLayout* vLayout_1 = new QVBoxLayout;
    vLayout_1->setAlignment(Qt::AlignTop);
    vLayout_1->setSpacing(20);
    QHBoxLayout* hLayout_1 = new QHBoxLayout;
    hLayout_1->setAlignment(Qt::AlignTop);
    QVBoxLayout* vLayout_2 = new QVBoxLayout;
    vLayout_2->setAlignment(Qt::AlignTop);
    vLayout_2->setSpacing(20);

    //формирование левой половины экрана
    QVBoxLayout* leftColumnPanel = new QVBoxLayout;
    QVBoxLayout* rightColumnPanel = new QVBoxLayout;

    QLabel* labelInfo = new QLabel("Тип информации");
    QLabel* labelName = new QLabel("Наименование");
    QLabel* labelAuthor = new QLabel("Автор");
    QLabel* labelPrice = new QLabel("Цена");
    QLabel* labelAditional = new QLabel("Примечание");

    editInfo->setFixedSize(400, 40);
    editName->setFixedSize(400, 40);
    editAuthor->setFixedSize(400, 40);
    editPrice->setFixedSize(400, 40);
    editAditional->setFixedSize(400, 50);

    leftColumnPanel->addWidget(labelInfo);
    rightColumnPanel->addWidget(editInfo);

    leftColumnPanel->addWidget(labelName);
    rightColumnPanel->addWidget(editName);

    leftColumnPanel->addWidget(labelAuthor);
    rightColumnPanel->addWidget(editAuthor);

    leftColumnPanel->addWidget(labelPrice);
    rightColumnPanel->addWidget(editPrice);

    leftColumnPanel->addWidget(labelAditional);
    rightColumnPanel->addWidget(editAditional);


    exitButton->setFixedSize(200, 40);

    hLayout_1->addLayout(leftColumnPanel);
    hLayout_1->addLayout(rightColumnPanel);
    vLayout_1->addLayout(hLayout_1);
    vLayout_1->addWidget(exitButton);


    // формирование правой половины экрана
    mainEdit->setFixedHeight(400);
    vLayout_2->addWidget(mainEdit);

    //добавление кнопок на правую половину экрана
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

    //итоговое формирование основного слоя приложения
    mainLayout->addLayout(vLayout_1);
    mainLayout->addLayout(vLayout_2);
    setLayout(mainLayout);
}

void Widget::createArrayObjects()
{
    // для проверки пути
    //qDebug() << QCoreApplication::applicationDirPath();
    //file.setFileName("D:/cpp_labs/QT/Lab07/InformationSystem/test.json");
    if(!mainEdit->toPlainText().isEmpty()){
        clearMainEdit();
    }

    QFile file;
    file.setFileName("../../inf/test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value;
    value = file.readAll();
    file.close();

    // Создаем объект JSON-документа
    QJsonDocument jsonDoc = QJsonDocument::fromJson(value.toUtf8());

    // создаем массив объектов из файла Json
    QJsonArray jsonArr = jsonDoc.array();
    if(objects.empty())
    {
        for(const QJsonValue &obj : jsonArr){
            if(obj.isObject()){
                QJsonObject jsonObj = obj.toObject();
                Unit unit;
                unit.type = jsonObj["Type"].toString();
                unit.name = jsonObj["Name"].toString();
                unit.author = jsonObj["Author"].toString();
                unit.price = jsonObj["Price"].toInt();
                unit.adition = jsonObj["Adition"].toString();

                objects.push_back(unit);
            }
        }
    }
    printToMainEdit(jsonArr);
}

void Widget::addElement()
{
    Unit unit;
    unit.type = editInfo->text();
    unit.name = editName->text();
    unit.author = editAuthor->text();
    unit.price = editPrice->text();
    unit.adition = editAditional->text();
    objects.push_back(unit);
    printToMainEdit();
}
