#ifndef RECEIVER_H
#define RECEIVER_H

#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <string>
#include <QTextCodec>
#include <QStringList>

class Receiver
{
public:
    Receiver() = default;
    QString task1(QString str1, QString str2);
    QString task2(QString str);
    QString task3(QString str1, QString str2);
};

#endif // RECEIVER_H
