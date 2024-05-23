#include "widget.h"
#include "ui_widget.h"

Graphics::Graphics(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 400);
}

void Graphics::setPolygon(const QPolygon& polygon) {
    this->polygon = polygon;
    update();
}

void Graphics::setFillColor(const QColor& color) {
    this->fillColor = color;
    update();
}

void Graphics::setLineWidth(int width) {
    this->widthOfLine = width;
    update();
}

void Graphics::setUsePen(bool usePen) {
    this->usePen = usePen;
    update();
}

void Graphics::setPenColor(const QColor& color) {
    this->penColor = color;
    update();
}

void Graphics::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if (usePen) {
        painter.setPen(QPen(penColor, widthOfLine));
        painter.setBrush(QBrush(fillColor));
    }
    else {
        painter.setPen(Qt::NoPen);
    }


    if (polygon.size() == 4) {
        QRect boundingRect = polygon.boundingRect();
        int a = qMax(boundingRect.width(), boundingRect.height()) / 2;
        int b = qMin(boundingRect.width(), boundingRect.height()) / 2;
        int radius = sqrt(a * a + b * b);
        QPoint center = boundingRect.center();
        painter.drawEllipse(center, radius, radius);
    }
    painter.drawPolygon(polygon);
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Графические примитивы");
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* menu = new QMenu("Меню", this);
    QAction* colorAction = new QAction("Выбрать цвет заливки", this);
    QAction* infoAction = new QAction("О проекте", this);
    QAction* exitAction = new QAction("Выход", this);

    menu->addAction(colorAction);
    menu->addAction(infoAction);
    menu->addAction(exitAction);
    menuBar->addMenu(menu);
    setMenuBar(menuBar);

    paintWidget = new Graphics;
    listWidget = new QListWidget;
    coordsOfPolygon = new QLineEdit;
    useOfPen = new QCheckBox("Использовать цвет пера");
    sliderWidth = new QSlider(Qt::Horizontal);
    sliderLabel = new QLabel("Толщина линии");

    sliderWidth->setRange(1, 20);
    sliderWidth->setValue(1);
    sliderWidth->setFixedSize(200, 20);


    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *centralWidget = new QWidget;

    layout->addWidget(listWidget);
    layout->addWidget(new QLabel("Координаты четырехугольника (писать через пробел всех 4 вершин)"));
    layout->addWidget(coordsOfPolygon);
    layout->addWidget(useOfPen);
    layout->addWidget(sliderLabel);
    layout->addWidget(sliderWidth);
    layout->addWidget(paintWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(colorAction, &QAction::triggered, this, &MainWindow::setBackGroundColor);
    connect(infoAction, &QAction::triggered, this, &MainWindow::showInformation);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
    connect(useOfPen, &QCheckBox::toggled, this, &MainWindow::usageOfPen);
    connect(sliderWidth, &QSlider::valueChanged, this, &MainWindow::changeLineWidth);


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setBackGroundColor() {
    QColor color = QColorDialog::getColor(Qt::white, paintWidget, "Выберите цвет заливки");
    if (color.isValid()) {
        paintWidget->setFillColor(color);
    }
}

void MainWindow::showInformation() {
    QMessageBox::information(this, "О проекте", "Описать окружность около прямоугольника, координаты которого вводятся.\nАвтор: Карачун Ярослав");
}

void MainWindow::changeLineWidth() {
    int valueOfWidth = sliderWidth->value();
    paintWidget->setLineWidth(valueOfWidth);
}

void MainWindow::usageOfPen(bool checked) {
    QString info = coordsOfPolygon->text();
    if(!info.isEmpty()){
        if(useOfPen->isChecked()){
            listWidget->addItem(info);
        }
        QStringList coords = info.split(' ');
        QPolygon polygonNew;
        for(size_t i = 0; i < coords.size(); i+=2){
            QPoint point(coords[i].toInt(), coords[i+1].toInt());
            polygonNew << point;
        }
        paintWidget->setPolygon(polygonNew);
        paintWidget->setUsePen(checked);
    }
}
