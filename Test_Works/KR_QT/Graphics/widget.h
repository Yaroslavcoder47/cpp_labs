#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QListWidget>
#include <QColorDialog>
#include <QCheckBox>
#include <QPainter>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include <QtMath>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Graphics : public QWidget {
    Q_OBJECT

public:
    Graphics(QWidget *parent = nullptr);
    ~Graphics() = default;

    void setPolygon(const QPolygon& polygon);
    void setFillColor(const QColor& color);
    void setLineWidth(int width);
    void setUsePen(bool usePen);
    void setPenColor(const QColor& color);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    QPolygon polygon;
    QColor fillColor = Qt::white;
    QColor penColor = Qt::black;
    int widthOfLine = 1;
    bool usePen = false;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setBackGroundColor();
    void showInformation();

    void changeLineWidth();
    void usageOfPen(bool checked);

private:
    Ui::MainWindow *ui;
    Graphics *paintWidget;
    QListWidget *listWidget;
    QLineEdit *coordsOfPolygon;
    QCheckBox *useOfPen;
    QSlider *sliderWidth;
    QLabel *sliderLabel;
};

#endif // WIDGET_H
