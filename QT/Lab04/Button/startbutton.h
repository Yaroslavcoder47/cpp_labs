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
    explicit StartButton(QWidget *parent = nullptr);
    ~StartButton();
private slots:
    void changeButtonColor();

private:
    Ui::StartButton *ui;
    QPushButton* btn;
};
#endif // STARTBUTTON_H
