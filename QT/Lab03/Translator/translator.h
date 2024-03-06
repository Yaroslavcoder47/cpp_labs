#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QObject>

class Translator : public QWidget
{
    Q_OBJECT

public:
    Translator(QWidget *parent = nullptr);
    ~Translator() = default;
signals:
    void setNumber();
public slots:
    void translateNumber();
private:
    QLabel *resultLabel;
    QLabel *infoLabel1;
    QLabel *infoLabel2;
    QLineEdit *number;
    QVBoxLayout *box;

};
#endif // TRANSLATOR_H
