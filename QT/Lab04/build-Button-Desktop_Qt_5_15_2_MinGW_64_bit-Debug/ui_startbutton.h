/********************************************************************************
** Form generated from reading UI file 'startbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTBUTTON_H
#define UI_STARTBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartButton
{
public:

    void setupUi(QWidget *StartButton)
    {
        if (StartButton->objectName().isEmpty())
            StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->resize(800, 600);

        retranslateUi(StartButton);

        QMetaObject::connectSlotsByName(StartButton);
    } // setupUi

    void retranslateUi(QWidget *StartButton)
    {
        StartButton->setWindowTitle(QCoreApplication::translate("StartButton", "StartButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartButton: public Ui_StartButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTBUTTON_H
