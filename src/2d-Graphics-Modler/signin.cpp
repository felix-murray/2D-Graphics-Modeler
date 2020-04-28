#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>

SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_pushButton_signin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test_user" && password == "test_pass")
    {
        QMessageBox::information(this, "Login_Success", "Username and Password is Corret.");
    }
    else
    {
        QMessageBox::warning(this, "Login_Failure", "The Username or Password is incorrect.");
    }
}
