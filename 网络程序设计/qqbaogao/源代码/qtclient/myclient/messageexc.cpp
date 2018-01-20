#include "messageexc.h"
#include "ui_messageexc.h"
#include "client.h"
#include "filetransender.h"
#include "filetransrecver.h"
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QFileDialog>
#include <QTextCodec>

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
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());    //设置不可改变窗口大小
    this->setWindowTitle(ttitle);

    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(recive()));
    timer->start(2);
}
MessageExc::~MessageExc()
{
    delete ui;
}

void MessageExc::sendms(){

    QString mymessage=ui->message->toPlainText();
    if(mymessage=="") return;
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
    if(size>0 && mymsg.type==1){
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
        ui->messageBrowser->append("[ "+ title + " ] "+time+ " : ");
        ui->messageBrowser->append(tr(mymsg.message));
     }
    if(size>0 && mymsg.type==2){
        QString filename=tr(mymsg.message);
        int btn=QMessageBox::information(this,tr("Message"),tr("Recive File %1 \n?").arg(filename),QMessageBox::Yes,QMessageBox::No);
        if(btn == QMessageBox::Yes){
            mymsg.type=4;
            write(fd,&mymsg,sizeof(mymsg));
            filetransrecver fr(0,fd,filename);
            fr.exec();
        }else{
            mymsg.type=3;   //拒绝
            write(fd,&mymsg,sizeof(mymsg));
        }
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

void MessageExc::on_file_trans_clicked()
{
    QString filepath=QFileDialog::getOpenFileName(this);


    //文件名
    QString fliename=filepath.right(filepath.size()-filepath.lastIndexOf('/')-1);
    if(fliename == "")return;
    MMSG msgx;
    msgx.type=2;
    QByteArray iua=fliename.toLatin1();
    char *myinfo=iua.data();
    strcpy(msgx.message,myinfo);
    write(fd,&msgx,sizeof(MMSG));
    read(fd,&msgx,sizeof(MMSG));
    if(msgx.type==3){ //拒绝接受
        QMessageBox::information(this,tr("Info"),tr("You Request was reject!"),QMessageBox::Ok);
    }
    if(msgx.type==4){//确认接收
        timer->stop();
        filetransender fs(0,fd,filepath);
        fs.exec();
        timer->start(2);
    }
    //qDebug() << fliename;

    /*
    FILE *fp=fopen(filename,"rb+");
    fseek(fp, 0, SEEK_END);// 指定到文件尾
    int flen = ftell(fp);//获取文件长度
    fseek(fp, 0, SEEK_SET);//指定到文件头

    FILE *ffp=fopen("/home/bluarry/test/hehe.jpg","wb+");
    char x[1024];
    int size=-1;
    while(1){
        size=fread(x,1024,1,fp);
        if(size==0) break;
        fwrite(x,1024,1,ffp);
    }

    fclose(fp);
    fclose(ffp);

    qDebug() << filename <<" "<<flen/(1024.0) << "KB";
    */
}

