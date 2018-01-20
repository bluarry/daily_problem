#include "filetransrecver.h"
#include "ui_filetransrecver.h"
#include "client.h"
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
filetransrecver::filetransrecver(QWidget *parent,int lfd,QString ffilename) :
    QDialog(parent),
    fd(lfd),
    filename(ffilename),
    ui(new Ui::filetransrecver)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    ui->transinfo->setText(tr("Wait For Ready"));
    recivesize=0;
    ui->progressBar->setValue(0);

    filepath=QFileDialog::getSaveFileName();

    QByteArray qba=filepath.toLatin1();
    char * filepath_r=qba.data();
    fp=fopen(filepath_r,"wb+");

    MYSG mymsg;
    memset(&mymsg,0,sizeof(mymsg));
    mymsg.type=6;
    write(fd,&mymsg,sizeof(mymsg));

    read(fd,&mymsg,sizeof(mymsg));  //收到的多余的信息，未知来源
    read(fd,&mymsg,sizeof(mymsg));
    filesize=mymsg.type;

    ui->progressBar->setMaximum(filesize);
    CNT=1;
    ui->transinfo->setText(tr("Reciver Ready"));

    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(recivefile()));
    timer->start(0.002);
}
filetransrecver::~filetransrecver()
{
    fclose(fp);
    delete timer;
    delete ui;
}
void filetransrecver::recivefile(){
     int cnt=1;
     MFILE M;
     memset(&M,0,sizeof(M));
     int size=recv(fd,&M,sizeof(M),MSG_DONTWAIT);;
     if(size>0 && CNT){
         if(M.type==7){
             if(cnt-->0) ui->transinfo->setText("Start Trans...");
             fwrite(M.x,1,1,fp);
             recivesize+=1*sizeof(char);
             ui->progressBar->setValue(recivesize);
             if(ui->progressBar->value() >= filesize) {
                 ui->transinfo->setText("Trans finished");
                 CNT=0;
             }
         }
         if(M.type==9){
             QMessageBox::information(this,tr("info"),tr("Sender Cancel Trans!!"),QMessageBox::Ok);
             ui->transinfo->setText("Trans Canceled!");
             CNT=0;
             on_filetranscancle_clicked();
         }
     }else if(CNT==0){
         timer->stop();
     }
}


void filetransrecver::on_filetranscancle_clicked()
{
    MFILE M;
    memset(&M,0,sizeof(M));
    M.type=8; //发送端中断
    write(fd,&M,sizeof(M));
    CNT=0;
    QDialog::reject();
}
