#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    buildInterface();
    connect(exitButton, &QPushButton::clicked, this, QApplication::quit);
    connect(openButton, &QPushButton::clicked, this, &Widget::createArrayObjects);
    //connect(openButton, &QPushButton::clicked, this, &Widget::clearMainEdit);
    connect(deleteButton, &QPushButton::clicked, this, &Widget::clearMainEdit);
    connect(addButton, &QPushButton::clicked, this, &Widget::addElement);
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

void calculateColumnWidths(const QVector<Unit>& units, int& maxTypeWidth, int& maxNameWidth, int& maxAuthorWidth, int& maxPriceWidth, int& maxAditionWidth) {
    for (const Unit& unit : units) {
        maxTypeWidth = std::max(maxTypeWidth, unit.type.length());
        maxNameWidth = std::max(maxNameWidth, unit.name.length());
        maxAuthorWidth = std::max(maxAuthorWidth, unit.author.length());
        maxPriceWidth = std::max(maxPriceWidth, QString::number(unit.price).length());
        maxAditionWidth = std::max(maxAditionWidth, unit.adition.length());
    }
}

void Widget::printToMainEdit()
{
    // форматирование текста на вывод
    int maxTypeWidth = QString("Type").length();
    int maxNameWidth = QString("Name").length();
    int maxAuthorWidth = QString("Author").length();
    int maxPriceWidth = QString("Price").length();
    int maxAditionWidth = QString("Adition").length();
    calculateColumnWidths(objects, maxTypeWidth, maxNameWidth, maxAuthorWidth, maxPriceWidth, maxAditionWidth);
    QString header = QString("%1   %2   %3   %4   %5").arg("Type", -maxTypeWidth).arg("Name", -maxNameWidth).arg("Author", -maxAuthorWidth).arg("Price",
-maxPriceWidth).arg("Adition", -maxAditionWidth);
    mainEdit->appendPlainText(header);
    mainEdit->appendPlainText(QString("-").repeated(header.length()));
    QString text;
    for(const Unit &val : objects){
        //text += QString("%1   %2   %3   %4   %5").arg(val.type, -maxTypeWidth).arg(val.name, -maxNameWidth+maxTypeWidth).arg(val.author, -maxAuthorWidth).arg(val.price,
        //-maxPriceWidth).arg(val.adition, -maxAditionWidth) + '\n';
        text += QString("%1 %2 %3 %4 %5\n")
                    .arg(val.type.leftJustified(maxTypeWidth, ' '))
                    .arg(val.name.leftJustified(maxNameWidth, ' '))
                    .arg(val.author.leftJustified(maxAuthorWidth, ' '))
                    .arg(QString::number(val.price).leftJustified(maxPriceWidth, ' '))
                    .arg(val.adition.leftJustified(maxAditionWidth, ' '));
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
        objects.clear();
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
    printToMainEdit();
}


void Widget::addElement()
{
    Unit unit;
    unit.type = editInfo->text();
    unit.name = editName->text();
    unit.author = editAuthor->text();
    unit.price = editPrice->text().toInt();
    unit.adition = editAditional->text();
    objects.push_back(unit);
    printToMainEdit();
}
