#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QTextCodec>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_loginin_btn_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    if(ui->in_username->text().isEmpty()){
        QMessageBox::information(this,QObject::tr("Note"),
                                    QObject::tr("User name is Empty!"),QMessageBox::Ok);
        ui->in_username->setFocus();
    }else if(ui->in_password->text().isEmpty()){
         QMessageBox::information(this,QObject::tr("Note"),
                                    QObject::tr("Password is Empty!"),QMessageBox::Ok);
         ui->in_password->setFocus();
    }else{

    }
}

void LoginWindow::on_exit_btn_clicked()
{
     QDialog::reject();
}
