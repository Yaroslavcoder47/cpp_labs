#include <QCoreApplication>
#include <iostream>
#include <QTextStream>


int main()
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
    return 0;
}
