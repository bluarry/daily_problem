#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include <QTimer>
#include "client.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "messageexc.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    int ret=0;

    MainWindow w;
    LoginWindow loginwin;
    Client* client=Client::Getinstance();

    bool ok=client->init(&loginwin);

    if(ok){ //初始化成功继续运行
        if(loginwin.exec() == QDialog::Accepted){
            w.setWindowTitle(QObject::tr(client->loginanme));
            w.show();
            ret=a.exec();
        }else{
            a.exit();
        }
    }else{
        a.exit();
    }
    return ret;
}
