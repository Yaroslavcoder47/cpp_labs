#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMouseEvent>
#include <QMainWindow>
#include <QLabel>
#include <vector>
#include <QRandomGenerator>
#include <QRect>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

signals:
    void makeLabel();

public slots:
    void addLabel();


private:
    Ui::MainWindow *ui;
    std::vector<QLabel*> labels_;
    bool checkIntersection(QRect a);
    void changeTextOnLabels(QString text);
};
#endif // MAINWINDOW_H
