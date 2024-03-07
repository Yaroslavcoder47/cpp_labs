/********************************************************************************
** Form generated from reading UI file 'translator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATOR_H
#define UI_TRANSLATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Translator
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Translator)
    {
        if (Translator->objectName().isEmpty())
            Translator->setObjectName(QString::fromUtf8("Translator"));
        Translator->resize(545, 400);
        centralwidget = new QWidget(Translator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 554, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(250);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(70, -1, 60, -1);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(200, 20));

        horizontalLayout_2->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, -1, 20, -1);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setMaximumSize(QSize(200, 100));
        lineEdit->setBaseSize(QSize(0, 0));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(200, 50));

        horizontalLayout_3->addWidget(pushButton);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(200, 100));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(160);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(comboBox);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_4);

        Translator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Translator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 545, 21));
        Translator->setMenuBar(menubar);
        statusbar = new QStatusBar(Translator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Translator->setStatusBar(statusbar);

        retranslateUi(Translator);

        QMetaObject::connectSlotsByName(Translator);
    } // setupUi

    void retranslateUi(QMainWindow *Translator)
    {
        Translator->setWindowTitle(QCoreApplication::translate("Translator", "Translator", nullptr));
        label->setText(QCoreApplication::translate("Translator", "Input your number", nullptr));
        label_3->setText(QCoreApplication::translate("Translator", "Result", nullptr));
        pushButton->setText(QCoreApplication::translate("Translator", "Translate", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Translator", "2", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Translator", "8", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Translator", "10", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Translator", "16", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("Translator", "2", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Translator", "8", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Translator", "10", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Translator", "16", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Translator: public Ui_Translator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATOR_H
