#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QString>
#include <QLabel>
#include <vector>
#include <cmath>
#include <QPair>

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

private:
    Ui::Widget *ui;
    QVector<QVector<QPushButton*>> buttons;

    QVector<QString> sign{"X", "O"};
    QPair<bool, QString> checkWin();
    size_t dim = 3;
    std::vector<std::vector<int>> check;
    size_t turn = 0;
};
#endif // WIDGET_H
