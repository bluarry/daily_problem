#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    MainWindow w;
    LoginWindow loginwin;

    if(loginwin.exec() == QDialog::Accepted){
        w.show();
    }




    return a.exec();
}
