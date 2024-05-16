#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    buildInterface();
    connect(exitButton, &QPushButton::clicked, this, QApplication::quit);
    connect(openButton, &QPushButton::clicked, this, &Widget::createArrayObjects);
    connect(deleteButton, &QPushButton::clicked, this, &Widget::clearMainEdit);
    connect(addButton, &QPushButton::clicked, this, &Widget::addElement);
    connect(saveButton, &QPushButton::clicked, this, &Widget::saveObjects);
    connect(searchButton, &QPushButton::clicked, this, &Widget::searchObjects);
    connect(sortButton, &QPushButton::clicked, this, &Widget::sortObjects);
    connect(checkName, &QCheckBox::stateChanged, this, &Widget::functionCheck);
    connect(checkAuthor, &QCheckBox::stateChanged, this, &Widget::functionCheck);
}

void Widget::functionCheck()
{
    if(checkName->isChecked()){
        checkAuthor->setEnabled(false);
    }
    else{
        checkAuthor->setEnabled(true);
    }
    if(checkAuthor->isChecked()){
        checkName->setEnabled(false);
    }
    else{
        checkName->setEnabled(true);
    }
}

void deleteLayout(QHBoxLayout* layout)
{
    layout->deleteLater();
    layout->deleteLater();
}

bool compName(Unit first, Unit second)
{
    return first.name < second.name;
}

bool compAuthor(Unit first, Unit second)
{
    return first.author < second.author;
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

void Widget::printToMainEdit(QVector<Unit>& objects)
{
    clearMainEdit();
    QString text;
    for(const Unit& unit : objects){
        text += QString("Type: %1\nName: %2\nAuthor: %3\nPrice: %4\nAdition: %5\n\n")
                    .arg(unit.type.leftJustified(maxTypeWidth, ' '))
                    .arg(unit.name.leftJustified(maxNameWidth, ' '))
                    .arg(unit.author.leftJustified(maxAuthorWidth, ' '))
                    .arg(unit.price.leftJustified(maxPriceWidth, ' '))
                    .arg(unit.adition.leftJustified(maxAditionWidth, ' '));
    }
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
    mainEdit->setReadOnly(true);
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
    vLayout_2->addWidget(checkName);
    vLayout_2->addWidget(checkAuthor);
    vLayout_2->addWidget(checkName);
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
                unit.price = jsonObj["Price"].toString();
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
    printToMainEdit(objects);
}

void Widget::saveObjects()
{
    QJsonArray jsonArr;
    for (const Unit& unit : objects) {
        QJsonObject jsonObject;
        jsonObject["Type"] = unit.type;
        jsonObject["Name"] = unit.name;
        jsonObject["Author"] = unit.author;
        jsonObject["Price"] = unit.price;
        jsonObject["Adition"] = unit.adition;
        jsonArr.append(jsonObject);
    }

    QJsonDocument jsonDoc(jsonArr);
    QFile file("../../inf/test.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }
    file.write(jsonDoc.toJson());
}

void Widget::searchObjects()
{
    QString name = "";
    QString type = "";
    QString author = "";
    QVector<Unit> searchObj;
    if(!editInfo->text().isEmpty()){
        type = editInfo->text();
        for(const Unit& unit : objects){
            if(unit.type == type){
                searchObj.push_back(unit);
            }
        }
    }
    if(!editName->text().isEmpty()){
        name = editName->text();
        for(const Unit& unit : objects){
            if(unit.name == name){
                searchObj.push_back(unit);
            }
        }
    }
    if(!editAuthor->text().isEmpty()){
        author = editAuthor->text();
        for(const Unit& unit : objects){
            if(unit.author == author){
                searchObj.push_back(unit);
            }
        }
    }
    printToMainEdit(searchObj);
}

void Widget::sortObjects()
{
    QVector<Unit> sortObj;
    if(checkName->checkState()){
        for(const Unit& unit : objects){
            if(unit.type == editInfo->text()){
                sortObj.push_back(unit);
            }
        }
        std::sort(sortObj.begin(), sortObj.end(), compName);
    }
    else if(checkAuthor->checkState()){
        for(const Unit& unit : objects){
            if(unit.type == editInfo->text()){
                sortObj.push_back(unit);
            }
        }
        std::sort(sortObj.begin(), sortObj.end(), compAuthor);
    }
    printToMainEdit(sortObj);
}
