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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Translator
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Translator)
    {
        if (Translator->objectName().isEmpty())
            Translator->setObjectName(QString::fromUtf8("Translator"));
        Translator->resize(800, 600);
        centralwidget = new QWidget(Translator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
    } // retranslateUi

};

namespace Ui {
    class Translator: public Ui_Translator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATOR_H
