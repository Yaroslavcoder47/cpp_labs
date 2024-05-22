#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsPixmapItem>

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
    void paintEvent(QPaintEvent*) override;
private:
    Ui::Widget *ui;
    QPixmap fox;
    QGraphicsPixmapItem* fox_item;
};
#endif // WIDGET_H
