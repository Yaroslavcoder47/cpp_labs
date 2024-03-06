#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

class Translator : public QWidget
{
    Q_OBJECT

public:
    Translator(QWidget *parent = nullptr);
    ~Translator() = default;

private:
};
#endif // TRANSLATOR_H
