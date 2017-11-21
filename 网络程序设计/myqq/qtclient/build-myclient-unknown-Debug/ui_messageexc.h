/********************************************************************************
** Form generated from reading UI file 'messageexc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEEXC_H
#define UI_MESSAGEEXC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageExc
{
public:
    QWidget *widget;
    QTextBrowser *messageBrowser;
    QToolButton *file_trans;
    QTextEdit *message;
    QPushButton *send;
    QPushButton *cancel;

    void setupUi(QDialog *MessageExc)
    {
        if (MessageExc->objectName().isEmpty())
            MessageExc->setObjectName(QString::fromUtf8("MessageExc"));
        MessageExc->resize(586, 739);
        widget = new QWidget(MessageExc);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 581, 721));
        messageBrowser = new QTextBrowser(widget);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));
        messageBrowser->setGeometry(QRect(20, 10, 551, 441));
        file_trans = new QToolButton(widget);
        file_trans->setObjectName(QString::fromUtf8("file_trans"));
        file_trans->setGeometry(QRect(460, 460, 81, 27));
        message = new QTextEdit(widget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(10, 500, 541, 171));
        send = new QPushButton(widget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(330, 680, 101, 41));
        cancel = new QPushButton(widget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(460, 680, 91, 41));
        messageBrowser->raise();
        file_trans->raise();
        message->raise();
        cancel->raise();
        send->raise();

        retranslateUi(MessageExc);

        QMetaObject::connectSlotsByName(MessageExc);
    } // setupUi

    void retranslateUi(QDialog *MessageExc)
    {
        MessageExc->setWindowTitle(QApplication::translate("MessageExc", "Messageexchangebox", 0, QApplication::UnicodeUTF8));
        file_trans->setText(QApplication::translate("MessageExc", "\346\226\207\344\273\266\344\274\240\350\276\223", 0, QApplication::UnicodeUTF8));
        send->setText(QApplication::translate("MessageExc", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("MessageExc", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageExc: public Ui_MessageExc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEEXC_H
