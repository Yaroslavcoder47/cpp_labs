#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVector>
#include <QPushButton>
#include <QDir>
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
    ~Widget();
private slots:
    void createArrayObjects();

private:
    QVector<Unit> objects;
    void buildInterface();
    QPushButton* exitButton = new QPushButton("Выйти");
    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* openButton = new QPushButton("Открыть");
    QPushButton* sortButton = new QPushButton("Сортировать");
    QPushButton* saveButton = new QPushButton("Сохранить");
    QPushButton* searchButton = new QPushButton("Поиск");
    QPushButton* deleteButton = new QPushButton("Очистить");
    QLineEdit* mainEdit = new QLineEdit();
    Ui::Widget *ui;
};
#endif // WIDGET_H