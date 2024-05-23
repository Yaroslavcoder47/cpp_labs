#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QColorDialog>
#include <QButtonGroup>
#include <QCheckBox>
#include <QPainter>
#include <QLineEdit>
#include <QRadioButton>
#include <QSlider>

class Graphics : public QWidget {
    Q_OBJECT

public:
    Graphics(QWidget *parent = nullptr);

    void setPolygon(const QPolygon &polygon);
    void setFillColor(const QColor &color);
    void setLineWidth(int width);
    void setUsePen(bool usePen);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    QPolygon polygon;
    QColor fillColor = Qt::white;
    int lineWidth = 1;
    bool usePen = false;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Graphics *graphicsWidget;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QButtonGroup *radioGroup;
    QSlider* widthOfPen;
    QCheckBox *checkBox;
};

#endif // MAINWINDOW_H
