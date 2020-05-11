#include "contact_us.h"
#include "ui_contact_us.h"

contact_us::contact_us(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact_us)
{
    ui->setupUi(this);
}

contact_us::~contact_us()
{
    delete ui;
}
