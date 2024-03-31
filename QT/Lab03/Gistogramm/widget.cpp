#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    for (size_t i = 0; i < dim; ++i) {
        data.append(QRandomGenerator::global()->bounded(1, 100));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int barWidth = width() / data.size(); // width of column

    int maxValue = *std::max_element(data.constBegin(), data.constEnd());
    for (size_t i = 0; i < data.size(); ++i) {
        int barHeight = static_cast<int>(static_cast<qreal>(data[i]) / maxValue * height());
        QRect rect(i * barWidth, height() - barHeight, barWidth, barHeight);
        painter.fillRect(rect, getRandomColor()); // random color of column

        painter.drawText(rect, Qt::AlignCenter, QString::number(data[i]));
    }
}

QColor Widget::getRandomColor()
{
    return QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                           QRandomGenerator::global()->bounded(256),
                           QRandomGenerator::global()->bounded(256));
}
