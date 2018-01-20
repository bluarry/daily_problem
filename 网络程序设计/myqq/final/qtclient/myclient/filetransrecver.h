#ifndef FILETRANSRECVER_H
#define FILETRANSRECVER_H

#include <QDialog>
#include <stdio.h>

namespace Ui {
class filetransrecver;
}

class filetransrecver : public QDialog
{
    Q_OBJECT

public:
     explicit filetransrecver(QWidget *parent = 0,int lfd=-1,QString ffilename="");
    ~filetransrecver();
    typedef struct MYSG{
        int type;
        char message[1024];
    }MYSG;
    typedef struct Mfile{
        int type;
        char x[1];
    }MFILE;

private slots:
    void recivefile();

    void on_filetranscancle_clicked();

private:
    QTimer *timer;
    int fd;
    int CNT;
    QString filename;
    int recivesize;
    int filesize;
    Ui::filetransrecver *ui;
    FILE* fp;
    QString filepath;
};

#endif // FILETRANSRECVER_H
