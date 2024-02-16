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

int main()
{
    int counter1 = 0;
    int counter2 = 0;
    QTextStream out(stdout);
    QTextStream in(stdin);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    out.setCodec(QTextCodec::codecForName("cp866"));
    //in.setCodec(QTextCodec::codecForName("cp866"));
    QString str = in.readLine();
    QStringList list = str.split(' ');
    foreach (QString word, list){
        if(word[0] == 'н'){
            counter1++;
        }
        if(word[word.length()-1] == 'р'){
            counter2++;
        }
    }
    out << "Количество слов, начинающихся с н: " << counter1 << Qt::endl;
    out << "Количество слов, заканчивающихся на р: " << counter2 << Qt::endl;
    return 0;
}
