#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "translator.h"
#include "ui_translator.h"

Translator::Translator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Translator)
{
    ui->setupUi(this);

    QLabel* inputData = new QLabel("Input:", this);
    inputData->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLineEdit* inputForm = new QLineEdit(this);

    QGridLayout* grid = new QGridLayout();

    grid->addWidget(inputData, 0, 0);
    grid->addWidget(inputForm, 0, 1);

    setLayout(grid);

}

Translator::~Translator()
{
    delete ui;
}
