#include <QCoreApplication>
#include <iostream>
#include <QTextStream>
#include <string>
#include <QTextCodec>
#include <QStringList>



void f1()
{
    QTextStream in(stdin);
    QTextStream out(stdout);
    QString str1, str2;
    in >> str1;
    in >> str2;

    for(int i = 0; i < str1.length(); ++i){
        if(str2.toLower().contains(str1.toLower()[i])){
            out << "yes ";
        }
        else{
            out << "no ";
        }
    }
    out << Qt::endl;
}

void f2()
{
    int counter1 = 0;
    int counter2 = 0;
    QTextStream out(stdout);
    out.setCodec(QTextCodec::codecForName("cp866"));

    QTextStream in(stdin);
    in.setCodec(QTextCodec::codecForName("cp866"));

    QString str = in.readLine();
    QStringList list = str.split(' ');

    foreach (QString word, list){
        if(word[0] == "н"){
            ++counter1;
        }
        if(word[word.length()-1] == "р"){
            ++counter2;
        }
    }
    out << QString("Количество слов, начинающихся с н: ") << counter1 << Qt::endl;
    out << QString("Количество слов, заканчивающихся на р: ") << counter2 << Qt::endl;
}

int main()
{
    f2();
    return 0;
}
