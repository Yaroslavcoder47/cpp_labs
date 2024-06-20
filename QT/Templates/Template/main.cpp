#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QSlider>
#include <QScrollBar>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QListWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>

// class MyWidget : public QWidget {
// public:
//     MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
//         QVBoxLayout *mainLayout = new QVBoxLayout(this);

//         // QLabel
//         QLabel *label = new QLabel("This is a QLabel", this);
//         mainLayout->addWidget(label);
//         label->text();


//         // QPushButton
//         QPushButton *button = new QPushButton("Click me", this);
//         mainLayout->addWidget(button);

//         // QCheckBox
//         QCheckBox *checkBox = new QCheckBox("Check me", this);
//         mainLayout->addWidget(checkBox);

//         // QRadioButton
//         QRadioButton *radioButton = new QRadioButton("Select me", this);
//         mainLayout->addWidget(radioButton);

//         // QGroupBox
//         QGroupBox *groupBox = new QGroupBox("Group Box", this);
//         QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox);
//         groupBoxLayout->addWidget(new QLabel("Inside GroupBox", this));
//         groupBox->setLayout(groupBoxLayout);
//         mainLayout->addWidget(groupBox);

//         // QSlider
//         QSlider *slider = new QSlider(Qt::Horizontal, this);
//         mainLayout->addWidget(slider);

//         // QScrollBar
//         QScrollBar *scrollBar = new QScrollBar(Qt::Horizontal, this);
//         mainLayout->addWidget(scrollBar);

//         // QLineEdit
//         QLineEdit *lineEdit = new QLineEdit(this);
//         mainLayout->addWidget(lineEdit);

//         // QTextEdit
//         QTextEdit *textEdit = new QTextEdit(this);
//         mainLayout->addWidget(textEdit);

//         // QSpinBox
//         QSpinBox *spinBox = new QSpinBox(this);
//         mainLayout->addWidget(spinBox);

//         // QListWidget
//         QListWidget *listWidget = new QListWidget(this);
//         listWidget->addItems({"Item 1", "Item 2", "Item 3"});
//         mainLayout->addWidget(listWidget);

//         // QTableWidget
//         QTableWidget *tableWidget = new QTableWidget(3, 3, this);
//         for (int row = 0; row < 3; ++row) {
//             for (int col = 0; col < 3; ++col) {
//                 tableWidget->setItem(row, col, new QTableWidgetItem(QString("Item %1,%2").arg(row).arg(col)));
//             }
//         }
//         mainLayout->addWidget(tableWidget);

//         // QComboBox
//         QComboBox *comboBox = new QComboBox(this);
//         comboBox->addItems({"Option 1", "Option 2", "Option 3"});
//         mainLayout->addWidget(comboBox);

//         // QTabWidget
//         QTabWidget *tabWidget = new QTabWidget(this);
//         tabWidget->addTab(new QLabel("Tab 1 Content", this), "Tab 1");
//         tabWidget->addTab(new QLabel("Tab 2 Content", this), "Tab 2");
//         mainLayout->addWidget(tabWidget);
//     }
// };

#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget widget;
    widget.resize(800, 600);
    widget.show();

    return app.exec();
}
