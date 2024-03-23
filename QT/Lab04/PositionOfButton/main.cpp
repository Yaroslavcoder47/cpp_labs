#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;

    QSlider verticalSlider(Qt::Vertical);
    QSlider horizontalSlider(Qt::Horizontal);

    QPushButton Button("Button");
    Button.setParent(&window);
    Button.setFixedSize(90,40);





    // Установка обработчика для перемещения вертикального ползунка


    // Размещение вертикального QSlider и QPushButton в вертикальном макете
    QVBoxLayout verticalLayout;
    verticalLayout.addWidget(&verticalSlider);
    //verticalLayout.addWidget(&Button);

    // Размещение горизонтального QSlider и QPushButton в горизонтальном макете
    QHBoxLayout horizontalLayout;
    horizontalLayout.addWidget(&horizontalSlider);

    // Размещение вертикального и горизонтального макетов в общем макете
    QVBoxLayout mainLayout;
    mainLayout.addLayout(&verticalLayout);
    mainLayout.addLayout(&horizontalLayout);

    window.setLayout(&mainLayout);
    window.setGeometry(100, 100, 800, 800);
    verticalSlider.setMaximum(window.height());
    horizontalSlider.setMaximum(window.width());
    verticalSlider.setValue(window.height());
    window.setWindowTitle("Slider and Button Demo");
    Button.move(0,0);
    Button.show();
    window.show();
    QObject::connect(&verticalSlider, &QSlider::valueChanged,
                     [&Button,&window](int value) {
                         Button.move(Button.x(),window.height() - value);
                     });

    // Установка обработчика для перемещения горизонтального ползунка
    QObject::connect(&horizontalSlider, &QSlider::valueChanged,
                     [&Button](int value) {
                         Button.move(value, Button.y());
                     });
    return app.exec();
}
