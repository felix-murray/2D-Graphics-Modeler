#include "customertest.h"
#include "ui_customertest.h"

customertest::customertest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customertest)
{
    ui->setupUi(this);
}

customertest::~customertest()
{
    delete ui;
}
