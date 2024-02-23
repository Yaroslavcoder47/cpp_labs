#include "receiver.h"

QString Receiver::task1(QString str1, QString str2)
{
    QString res;
    //QTextStream in(stdin);
    //QTextStream out(stdout);
    //QString str1, str2;
    //in >> str1;
    //in >> str2;

    for(int i = 0; i < str1.length(); ++i){
        if(str2.toLower().contains(str1.toLower()[i])){
            res += "yes ";
        }
        else{
            res += "no ";
        }
    }
    //out << Qt::endl;
    return res;
}

//функция возвращает строку, на 0 позиции содержится кол-во строк, которые начинаются на н
// а на 1 позиции содержится кол-во строк, которые заканчиваются на р
QString Receiver::task2(QString str)
{
    QString res;
    int counter1 = 0;
    int counter2 = 0;
    // QTextStream out(stdout);
    // out.setCodec(QTextCodec::codecForName("cp866"));

    // QTextStream in(stdin);
    // in.setCodec(QTextCodec::codecForName("cp866"));

    // QString str = in.readLine();
    QStringList list = str.split(' ');

    foreach (QString word, list){
        if(word[0].toLower() == "н"){
            ++counter1;
        }
        if(word[word.length()-1] == "р"){
            ++counter2;
        }
    }
    // out << QString("Количество слов, начинающихся с н: ") << counter1 << Qt::endl;
    // out << QString("Количество слов, заканчивающихся на р: ") << counter2 << Qt::endl;
    res += QString::number(counter1);
    res += QString::number(counter2);
    return res;
}

QString Receiver::task3(QString str1, QString str2)
{
    QString res;
    // QTextStream in(stdin);
    // in.setCodec(QTextCodec::codecForName("cp866"));
    // QTextStream out(stdout);
    // out.setCodec(QTextCodec::codecForName("cp866"));
    // QString str1 = in.readLine();
    // QString str2 = in.readLine();

    QStringList list1 = str1.toLower().split(' ');
    QStringList list2 = str2.toLower().split(' ');

    foreach (QString word, list1) {
        if(list2.contains(word)){
            //out << "yes ";
            res += "yes ";
        }
        else
        {
            res += "no ";
            //out << "no ";
        }
    }
    //out << Qt::endl;
    return res;
}
