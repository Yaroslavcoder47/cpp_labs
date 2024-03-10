#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>

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
private slots:
    void changeButtonColor();

protected:
    void enterEvent(QEvent *event) override;

private:
    Ui::StartButton *ui;



    QPushButton *btn;
};
#endif // STARTBUTTON_H
