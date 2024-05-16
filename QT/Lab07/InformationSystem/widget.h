#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVector>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QFile>
// libraries for Json format
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "unit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() = default;
private slots:
    void createArrayObjects();
    void addElement();
private:
    QLineEdit* editInfo = new QLineEdit;
    QLineEdit* editName = new QLineEdit;
    QLineEdit* editAuthor = new QLineEdit;
    QLineEdit* editPrice = new QLineEdit;
    QLineEdit* editAditional = new QLineEdit;

    QPushButton* exitButton = new QPushButton("Выйти");
    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* openButton = new QPushButton("Открыть");
    QPushButton* sortButton = new QPushButton("Сортировать");
    QPushButton* saveButton = new QPushButton("Сохранить");
    QPushButton* searchButton = new QPushButton("Поиск");
    QPushButton* deleteButton = new QPushButton("Очистить");
    QPlainTextEdit* mainEdit = new QPlainTextEdit();

    QVector<Unit> objects;
    void buildInterface();
    void printToMainEdit(QJsonArray& units);
    void printToMainEdit();
    void clearMainEdit();

    int maxTypeWidth = QString("Type").length();
    int maxNameWidth = QString("Name").length();
    int maxAuthorWidth = QString("Author").length();
    int maxPriceWidth = QString("Price").length();
    int maxAditionWidth = QString("Adition").length();
};
#endif // WIDGET_H
