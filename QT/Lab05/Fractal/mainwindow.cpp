#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int width = width();
    int height = heigth();
    dots_ = qPow(2, qCeil(std::log2f(qMax(width, height) - 1))) + 1;
    plazma_.resize(dots_);
    for(auto& item : plazma_){
        item.resize(dots_);
        for(auto& item1 : item){
            item1 = nullptr;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDotsColor()
{
    plazma_[0][0] = QColor(Qt::red);
    plazma_[dots_ - 1][0] = QColor(Qt::green);
    plazma_[0][dots_ - 1] = QColor(Qt::blue);
    plazma_[dots_ - 1][dots_ - 1] = QColor(Qt::yellow);
    int x1 = 0;
    int y1 = 0;
    int x2 = dots_ - 1;
    int y2 = dots_ - 1;

    //Шаг 2. Шаг diamond. Нахождение срединной точки, присваивание ей значения, на основе среднего от угловых, плюс случайное число.
    int xCenter = (x2 - x1) / 2;
    int yCenter = (y2 - y1) / 2;
    int redCenter = (plazma_[x1][y1].red() + plazma_[x1][y2].red() + plazma_[x2][y1].red() + plazma_[x2][y2].red()) / 4;
    int greenCenter = (plazma_[x1][y1].green() + plazma_[x1][y2].green() + plazma_[x2][y1].green() + plazma_[x2][y2].green()) / 4;
    int blueCenter = (plazma_[x1][y1].blue() + plazma_[x1][y2].blue() + plazma_[x2][y1].blue() + plazma_[x2][y2].blue()) / 4;

    redCenter = (QRandomGenerator::global()->bounded(-30, 30) + redCenter) % 256;
    greenCenter = (QRandomGenerator::global()->bounded(-30, 30) + greenCenter) % 256;
    blueCenter = (QRandomGenerator::global()->bounded(-30, 30) + blueCenter) % 256;
    QColor colorCenter = QColor(redCenter, greenCenter, blueCenter);
    plazma_[xCenter][yCenter] = colorCenter;

    //Шаг 3. Шаг square. Нахождение срединных точек для ромбов отмеченных черными
    //точками (на этом шаге, по одной точке каждого ромба выходят за пределы массива). Плюс случайное число.
    int xLeft = x1;
    int yLeft = yCenter;
    int xRight = x2;
    int yRight = yCenter;
    int xBottom = xCenter;
    int yBottom = y1;
    int xTop = xCenter;
    int yTop = y2;
    //находим цвет левой точки
    int redLeft = plazma_[x1][y1].red() + plazma_[x1][y2].red() + plazma_[xCenter][yCenter].red();
    int greenLeft = plazma_[x1][y1].green() + plazma_[x1][y2].green() + plazma_[xCenter][yCenter].green();
    int blueLeft = plazma_[x1][y1].blue() + plazma_[x1][y2].blue() + plazma_[xCenter][yCenter].blue();
    int xLeftLeft = 2 * x1 - xCenter; //x1 - (xCenter - x1);
    if (xLeftLeft >= 0){
        redLeft += plazma_[xLeftLeft][yCenter].red();
        greenLeft += plazma_[xLeftLeft][yCenter].green();
        blueLeft += plazma_[xLeftLeft][yCenter].blue();
        redLeft /= 4;
        greenLeft /= 4;
        blueLeft /= 4;
    }
    else {
        redLeft /= 3;
        greenLeft /= 3;
        blueLeft /= 3;
    }
    //находим цвет правой точки
    int redRight = plazma_[x2][y1].red() + plazma_[x2][y2].red() + plazma_[xCenter][yCenter].red();
    int greenRight = plazma_[x2][y1].green() + plazma_[x2][y2].green() + plazma_[xCenter][yCenter].green();
    int blueRight = plazma_[x2][y1].blue() + plazma_[x2][y2].blue() + plazma_[xCenter][yCenter].blue();
    int xRightRight = 2 * x2 - xCenter; //x2 + (x2 - xCenter);
    if (xRightRight < dots_){
        redRight += plazma_[xRightRight][yCenter].red();
        greenRight += plazma_[xRightRight][yCenter].green();
        blueRight += plazma_[xRightRight][yCenter].blue();
        redRight /= 4;
        greenRight /= 4;
        blueRight /= 4;
    }
    else {
        redRight /= 3;
        greenRight /= 3;
        blueRight /= 3;
    }

}
