/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QPushButton *filetranscancle;
    QProgressBar *progressBar;
    QPushButton *filetransstart;
    QLabel *transinfo;
    QPushButton *filetranspause;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QString::fromUtf8("Sender"));
        Sender->resize(400, 300);
        filetranscancle = new QPushButton(Sender);
        filetranscancle->setObjectName(QString::fromUtf8("filetranscancle"));
        filetranscancle->setGeometry(QRect(270, 220, 91, 51));
        progressBar = new QProgressBar(Sender);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 130, 381, 51));
        progressBar->setValue(0);
        filetransstart = new QPushButton(Sender);
        filetransstart->setObjectName(QString::fromUtf8("filetransstart"));
        filetransstart->setGeometry(QRect(40, 220, 91, 51));
        transinfo = new QLabel(Sender);
        transinfo->setObjectName(QString::fromUtf8("transinfo"));
        transinfo->setGeometry(QRect(0, 30, 401, 81));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        transinfo->setFont(font);
        transinfo->setLayoutDirection(Qt::LeftToRight);
        transinfo->setAlignment(Qt::AlignCenter);
        filetranspause = new QPushButton(Sender);
        filetranspause->setObjectName(QString::fromUtf8("filetranspause"));
        filetranspause->setGeometry(QRect(150, 220, 91, 51));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Dialog", 0, QApplication::UnicodeUTF8));
        filetranscancle->setText(QApplication::translate("Sender", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        filetransstart->setText(QApplication::translate("Sender", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        transinfo->setText(QApplication::translate("Sender", "Wait For Start", 0, QApplication::UnicodeUTF8));
        filetranspause->setText(QApplication::translate("Sender", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
