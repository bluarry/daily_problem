#ifndef FILETRANSENDER_H
#define FILETRANSENDER_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class filetransender;
}

class filetransender : public QDialog
{
    Q_OBJECT

public:
    explicit filetransender(QWidget *parent = 0,int lfd=-1,QString xfilepath="");
    ~filetransender();
    typedef struct MYSG{
        int type;
        char message[1024];
    }MYSG;
    typedef struct Mfile{
        int type;
        char x[1];
    }MFILE;

private slots:
    void on_filetransstart_clicked();
    void sendfile();
    void on_filetranscancle_clicked();
    void recivesig();

private:
    int min(int a,int b);
    int fd;
    QTimer* timer;
    QString filepath;
    FILE *fp;   //文件指针
    bool CTN; //是否被中断
    int flen; //文件大小
    int sendsize;
    Ui::filetransender *ui;
};

#endif // FILETRANSENDER_H
