#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

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
    void placeWidget(QString widgetName, char count);

private:
    Ui::Widget *ui;
    QString widgetToPlace;
    char count;
};
#endif // WIDGET_H
