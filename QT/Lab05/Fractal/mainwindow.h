#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QColor>
#include <QtMath>
#include <QPainter>
#include <QDebug>
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
private:
    Ui::MainWindow *ui;
    const int delta = 50;
    int dots_;
    QVector<QVector<QColor>> plazma_;
    void fillPlazma (int& , int&, int&, int&);
    void initDotsColor();
protected:
    void paintEvent(QPaintEvent *qp) override;
};
#endif // MAINWINDOW_H
