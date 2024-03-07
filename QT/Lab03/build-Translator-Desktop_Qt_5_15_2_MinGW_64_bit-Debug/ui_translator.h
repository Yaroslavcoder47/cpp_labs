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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Translator
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Translator)
    {
        if (Translator->objectName().isEmpty())
            Translator->setObjectName(QString::fromUtf8("Translator"));
        Translator->resize(800, 600);
        centralwidget = new QWidget(Translator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 290, 41, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 200, 151, 81));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(380, 200, 151, 81));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 160, 121, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(400, 160, 49, 16));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(440, 290, 41, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 210, 131, 51));
        Translator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Translator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        comboBox->setItemText(0, QCoreApplication::translate("Translator", "2", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Translator", "8", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Translator", "10", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Translator", "16", nullptr));

        label->setText(QCoreApplication::translate("Translator", "Input your number", nullptr));
        label_3->setText(QCoreApplication::translate("Translator", "Result", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Translator", "2", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Translator", "8", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Translator", "10", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Translator", "16", nullptr));

        pushButton->setText(QCoreApplication::translate("Translator", "Translate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Translator: public Ui_Translator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATOR_H
