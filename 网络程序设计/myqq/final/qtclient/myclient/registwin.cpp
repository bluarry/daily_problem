#include "registwin.h"
#include "ui_registwin.h"
#include "client.h"
#include <QString>
#include <QTextCodec>
registwin::registwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registwin)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

registwin::~registwin()
{
    delete ui;
}


void registwin::on_regist_re_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    if(ui->username_edit->text().isEmpty()){
        QMessageBox::information(this,QObject::tr("Note"),
                                    QObject::tr("Username is Empty!"),QMessageBox::Ok);
        ui->username_edit->setFocus();
    }else if(ui->userpasswd->text().isEmpty()){
         QMessageBox::information(this,QObject::tr("Note"),
                                    QObject::tr("Password is Empty!"),QMessageBox::Ok);
         ui->userpasswd->setFocus();
    }else{
        QString username_scan=ui->username_edit->text();
         QByteArray ba = username_scan.toLatin1();
        char* real_username=ba.data();

        QString password_scan=ui->userpasswd->text();
         QByteArray ba2 = password_scan.toLatin1();
        char* real_password=ba2.data();
        Client* client=Client::Getinstance();

        int ret=client->regist(real_username,real_password);

        if(ret){
            QDialog::accept();
        }else{
            QWidget x;
            QMessageBox::warning(&x,tr("Warning"),
                                 tr("username or aleardy exists!")
                                 ,QMessageBox::Abort);
            ui->username_edit->setText("");
            ui->userpasswd->setText("");
        }
    }

}

void registwin::on_cancel_re_clicked()
{
   this->hide();
}
