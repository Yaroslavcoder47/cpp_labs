#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <direct.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QGraphicsPixmapItem>
#include <QSlider>
#include <QRect>
#include <QFile>
#include <QDebug>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

enum class DirectionTypes {
    kLeft,
    kRight,
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() = default;
    void SetupScene();
    void SetupFox();
    void timerEvent(QTimerEvent* event) override;

private:
    QGraphicsScene* scene_;
    QGraphicsView* view_;
    QPixmap fox_;
    QGraphicsPixmapItem* fox_item_;
    QPixmap field_;
    QSlider* length_;
    QSlider* height_;

    double jump_length_{60};
    double jump_height_{100};
    int fox_width_{0};
    double x_{0}, y_{0};
    DirectionTypes direction_{DirectionTypes::kRight};
    QBasicTimer animation_timer_;
};
#endif // WIDGET_H
