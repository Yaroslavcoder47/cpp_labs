#include "widget.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

Graphics::Graphics(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 400);
}

void Graphics::setPolygon(const QPolygon &polygon) {
    this->polygon = polygon;
    update();
}

void Graphics::setFillColor(const QColor &color) {
    this->fillColor = color;
    update();
}

void Graphics::setLineWidth(int width) {
    this->lineWidth = width;
    update();
}

void Graphics::setUsePen(bool usePen) {
    this->usePen = usePen;
    update();
}

void Graphics::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if (usePen) {
        painter.setPen(QPen(Qt::black, lineWidth));
    } else {
        painter.setPen(Qt::NoPen);
    }
    painter.setBrush(QBrush(fillColor));

    painter.drawPolygon(polygon);

    // Drawing the circle around the polygon
    if (polygon.size() == 4) {
        QRect boundingRect = polygon.boundingRect();
        int radius = qMax(boundingRect.width(), boundingRect.height()) / 2;
        QPoint center = boundingRect.center();
        painter.drawEllipse(center, radius, radius);
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Графические примитивы");

    graphicsWidget = new Graphics;
    listWidget = new QListWidget;
    lineEdit = new QLineEdit;
    widthOfPen = new QSlider(Qt::Horizontal);
    QLabel* sliderLabel = new QLabel("Толщина линии:");

    // Slider settings
    widthOfPen->setRange(1, 20); // Установим диапазон от 1 до 10
    widthOfPen->setValue(1);
    widthOfPen->setFixedSize(100, 20);



    radioGroup = new QButtonGroup(this);
    auto *radioButton1 = new QRadioButton("1 px");
    auto *radioButton2 = new QRadioButton("3 px");
    auto *radioButton3 = new QRadioButton("5 px");
    checkBox = new QCheckBox("Использовать цвет пера");
    auto *layout = new QVBoxLayout;
    auto *centralWidget = new QWidget;

    radioGroup->addButton(radioButton1, 1);
    radioGroup->addButton(radioButton2, 3);
    radioGroup->addButton(radioButton3, 5);

    layout->addWidget(listWidget);
    layout->addWidget(new QLabel("Координаты четырехугольника"));
    layout->addWidget(lineEdit);
    layout->addWidget(widthOfPen);
    layout->addWidget(sliderLabel);
    layout->addWidget(radioButton1);
    layout->addWidget(radioButton2);
    layout->addWidget(radioButton3);
    layout->addWidget(checkBox);
    layout->addWidget(graphicsWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Menu setup
    auto *menuBar = new QMenuBar(this);
    auto *menu = new QMenu("Меню", this);
    auto *colorAction = new QAction("Выбрать цвет фона", this);
    auto *infoAction = new QAction("О проекте", this);
    auto *exitAction = new QAction("Выход", this);

    menu->addAction(colorAction);
    menu->addAction(infoAction);
    menu->addAction(exitAction);
    menuBar->addMenu(menu);
    setMenuBar(menuBar);

    // Connect signals and slots
    connect(colorAction, &QAction::triggered, this, [this](){
        QColor color = QColorDialog::getColor(Qt::white, graphicsWidget, "Выберите цвет фона");
        if (color.isValid()) {
            graphicsWidget->setFillColor(color);
        }
    });

    connect(infoAction, &QAction::triggered, this, [](){
        QMessageBox::information(nullptr, "О проекте", "Приложение для работы с графическими примитивами.\nАвтор: Ваше имя");
    });

    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    connect(radioGroup, QOverload<int>::of(&QButtonGroup::idClicked), graphicsWidget, &Graphics::setLineWidth);
    connect(checkBox, &QCheckBox::toggled, graphicsWidget, &Graphics::setUsePen);

    // Example polygon
    QPolygon polygon;
    polygon << QPoint(150, 100) << QPoint(450, 100) << QPoint(450, 300) << QPoint(150, 300);
    graphicsWidget->setPolygon(polygon);

    // Example coordinates
    listWidget->addItem("150, 100");
    listWidget->addItem("450, 100");
    listWidget->addItem("450, 300");
    listWidget->addItem("150, 300");

    // Update lineEdit when item in listWidget is selected
    connect(listWidget, &QListWidget::itemClicked, [this](QListWidgetItem *item){
        lineEdit->setText(item->text());
    });
}

MainWindow::~MainWindow() {
    // Destructor implementation
}
