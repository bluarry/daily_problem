#ifndef MESSAGEEXC_H
#define MESSAGEEXC_H

#include <QDialog>
#include <QThread>
#include <QSemaphore>
namespace Ui {
class MessageExc;
}

class MessageExc : public QDialog
{
    Q_OBJECT

public:
    explicit MessageExc(QWidget *parent = 0);
    explicit MessageExc(QWidget *parent = 0,int lfd=-1,QString ttitle="");
    ~MessageExc();
    typedef struct MMSG{
        int type;
        char message[1024];
    }MMSG;

private slots:
    void on_cancel_clicked();
    void recive();

    void on_send_clicked();

    void on_file_trans_clicked();


private:
    int fd;
    MMSG mymsg;
    QString title;
    Ui::MessageExc *ui;
    QTimer *timer ;
    void sendms();

};

#endif // MESSAGEEXC_H
