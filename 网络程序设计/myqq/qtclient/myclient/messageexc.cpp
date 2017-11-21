#include "messageexc.h"
#include "ui_messageexc.h"
#include "client.h"
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QThread>
#include <QSemaphore>
MessageExc::MessageExc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageExc)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());    //设置不可改变窗口大小

}
MessageExc::MessageExc(QWidget *parent,int lfd,QString ttitle):
    QDialog(parent),
    fd(lfd),
    title(ttitle),
    ui(new Ui::MessageExc)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());    //设置不可改变窗口大小
    this->setWindowTitle(ttitle);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(recive()));
    timer->start(2);
}
MessageExc::~MessageExc()
{
    delete ui;
}

void MessageExc::sendms(){

    QString mymessage=ui->message->toPlainText();
    ui->message->setText("");

    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
    ui->messageBrowser->append("[ "+ tr(" me ")+ "] "+time+ " : ");
    ui->messageBrowser->append(mymessage);

    QByteArray uba = mymessage.toLatin1();
    char * x=uba.data();
    strcpy(mymsg.message,x);
    mymsg.type=1;

    write(fd,&mymsg,sizeof(mymsg));

}

void MessageExc::recive(){
    memset(mymsg.message,0,1024);

    int size=recv(fd,&mymsg,1024,MSG_DONTWAIT);
    while(size>0 && mymsg.type==1){
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
        ui->messageBrowser->append("[ "+ title + " ] "+time+ " : ");
        ui->messageBrowser->append(tr(mymsg.message));
        size=recv(fd,&mymsg,1024,MSG_DONTWAIT);
     }
}



void MessageExc::on_cancel_clicked()
{
    QDialog::reject();
}


void MessageExc::on_send_clicked()
{
    sendms();
}
