#ifndef UNIT_H
#define UNIT_H

#include <QString>

class Unit{
public:
    Unit() = default;
    ~Unit() = default;

    QString type;
    QString name;
    QString author;
    int price;
    QString adition;
};

#endif // UNIT_H
