#include "filetransender.h"
#include "ui_filetransender.h"
#include "client.h"
#include <QByteArray>
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

filetransender::filetransender(QWidget *parent,int lfd,QString xfilepath) :
    QDialog(parent),
    fd(lfd),
    filepath(xfilepath),
    ui(new Ui::filetransender)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    //中端与否
    CTN=true;

    //初始化文件指针
    QByteArray uba = filepath.toLatin1();
    char* filpathename=uba.data();
    fp=NULL;
    fp=fopen(filpathename,"rb+");
    if(fp==NULL) return;
    //初始化文件大小
    fseek(fp, 0, SEEK_END);// 指定到文件尾
    flen = ftell(fp);//获取文件长度
    fseek(fp, 0, SEEK_SET);//指定到文件头
    //已发送大小
    sendsize=0;
    //界面初始化
    ui->transinfo->setText(tr("Wait for Reciver Ready"));
    ui->progressBar->setMaximum(flen);
    ui->progressBar->setValue(sendsize);

    MYSG mymsg;
    memset(&mymsg,0,sizeof(mymsg));
    read(fd,&mymsg,sizeof(mymsg));

    if(mymsg.type==6){//接受端就绪
        ui->transinfo->setText(tr("Reciver Ready!"));
        mymsg.type=flen;
        write(fd,&mymsg,sizeof(mymsg));
    }
    timer=NULL;
    QTimer *canceltimer=new QTimer(this);
    connect(canceltimer, SIGNAL(timeout()), this, SLOT(recivesig()));
    canceltimer->start(1);
}
void filetransender::recivesig(){
    MFILE M;
    int size=recv(fd,&M,sizeof(M),MSG_DONTWAIT);
    if(size>0 && CTN){
        if(M.type==8){//接收端取消
            QMessageBox::information(this,tr("info"),tr("Sender Cancel Trans!!"),QMessageBox::Ok);
            ui->transinfo->setText("Trans Canceled!");
            CTN=0;
            QDialog::reject();
        }
    }
}

int filetransender::min(int a,int b){
    return a>b?b:a;
}
filetransender::~filetransender()
{
   delete ui;
   if(timer!=NULL){
         delete timer;
        timer=NULL;
   }
   if(fp!=NULL)
    {
       fclose(fp);
       fp=NULL;
    }
}

void filetransender::on_filetransstart_clicked()
{
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendfile()));
    if(CTN!=false)
        timer->start(0.001);
    else{
        timer->stop();
    }
}
void filetransender::sendfile(){
    if(CTN==false) return ;
    MFILE M;
    memset(&M,0,sizeof(M));
    ui->transinfo->setText("Start Trans...");
    if(!feof(fp) && CTN){
        M.type=7;
        fread(M.x,1,1,fp);
        write(fd,&M,sizeof(M));
        sendsize+=1*sizeof(char);
        ui->progressBar->setValue(sendsize);
    }else{
        ui->transinfo->setText("Trans finished");
        CTN=false;
        timer->stop();
    }
}
void filetransender::on_filetranscancle_clicked()
{
    MFILE M;
    memset(&M,0,sizeof(M));
    M.type=9; //发送端中断
    write(fd,&M,sizeof(M));
    CTN=0;
    QDialog::reject();
}
