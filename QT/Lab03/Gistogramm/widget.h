#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QVector>
#include <QRect>
#include <QRandomGenerator>
#include <QColor>
#include <QFont>

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

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    QVector<int> data;
    size_t dim = 10;
    QColor getRandomColor();
};
#endif // WIDGET_H
