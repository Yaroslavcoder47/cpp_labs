#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QColor>
#include <QtMath>
#include <cmath>
#include <QRandomGenerator>

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
    void initDotsColor();

private:
    Ui::MainWindow *ui;
    int dots_;
    QVector<QVector<QColor>> plazma_;
    void fillPlazma (int& , int&, int&, int&);
    const int delta = 30;
protected:
    void paintEvent (QPaintEvent *qp) override;
};
#endif // MAINWINDOW_H
