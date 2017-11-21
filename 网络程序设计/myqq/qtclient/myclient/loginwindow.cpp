#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "client.h"
#include "registwin.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <QString>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
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
        QString username_can=ui->in_username->text();
         QByteArray ba = username_can.toLatin1();
        char* username_real=ba.data();
        QString password_can=ui->in_password->text();
        ba = password_can.toLatin1();
        char* password_real=ba.data();

        Client* client=Client::Getinstance();

        if(client->login(username_real,password_real)){
            QDialog::accept();
        }else{
            QWidget x;
            QMessageBox::warning(&x,tr("Warning"),
                                 tr("username or password Error!")
                                 ,QMessageBox::Abort);
            ui->in_password->setText(tr(""));
        }
    }
}

void LoginWindow::on_exit_btn_clicked()
{
     QDialog::reject();
     exit(0);
}
//注册按钮被按下响应事件
void LoginWindow::on_regist_btn_clicked()
{
    registwin rw;
    if(rw.exec()==QDialog::Accepted){
        QMessageBox::information(this,QObject::tr("Note"),
                                   QObject::tr("Regist Success"),QMessageBox::Ok);
    }
}
