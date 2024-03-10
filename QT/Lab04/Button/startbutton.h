#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class StartButton;
}
QT_END_NAMESPACE

class StartButton : public QWidget
{
    Q_OBJECT

public:
    StartButton(QWidget *parent = nullptr);
    ~StartButton();

private:
    Ui::StartButton *ui;
    QPushButton* btn = new QPushButton("Click me");
};
#endif // STARTBUTTON_H
