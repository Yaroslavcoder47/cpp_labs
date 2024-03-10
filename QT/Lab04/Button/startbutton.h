#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QString>
#include <QRandomGenerator>

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

private:
    Ui::StartButton *ui;

    class Button : public QPushButton{
    public:
        Button(const QString &text, QWidget *parent = nullptr);
    protected:
        void enterEvent(QEvent *event) override;
    };

    Button *btn;
};
#endif // STARTBUTTON_H
