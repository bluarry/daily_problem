/********************************************************************************
** Form generated from reading UI file 'filetransender.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSENDER_H
#define UI_FILETRANSENDER_H

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

class Ui_filetransender
{
public:
    QPushButton *filetranscancle;
    QProgressBar *progressBar;
    QLabel *transinfo;
    QPushButton *filetransstart;

    void setupUi(QDialog *filetransender)
    {
        if (filetransender->objectName().isEmpty())
            filetransender->setObjectName(QString::fromUtf8("filetransender"));
        filetransender->resize(453, 303);
        filetranscancle = new QPushButton(filetransender);
        filetranscancle->setObjectName(QString::fromUtf8("filetranscancle"));
        filetranscancle->setGeometry(QRect(250, 220, 131, 51));
        progressBar = new QProgressBar(filetransender);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 130, 381, 51));
        progressBar->setValue(0);
        transinfo = new QLabel(filetransender);
        transinfo->setObjectName(QString::fromUtf8("transinfo"));
        transinfo->setGeometry(QRect(20, 30, 401, 81));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        transinfo->setFont(font);
        transinfo->setLayoutDirection(Qt::LeftToRight);
        transinfo->setAlignment(Qt::AlignCenter);
        filetransstart = new QPushButton(filetransender);
        filetransstart->setObjectName(QString::fromUtf8("filetransstart"));
        filetransstart->setGeometry(QRect(60, 220, 131, 51));

        retranslateUi(filetransender);

        QMetaObject::connectSlotsByName(filetransender);
    } // setupUi

    void retranslateUi(QDialog *filetransender)
    {
        filetransender->setWindowTitle(QApplication::translate("filetransender", "\345\217\221\351\200\201\347\253\257", 0, QApplication::UnicodeUTF8));
        filetranscancle->setText(QApplication::translate("filetransender", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        transinfo->setText(QApplication::translate("filetransender", "Wait For Start", 0, QApplication::UnicodeUTF8));
        filetransstart->setText(QApplication::translate("filetransender", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class filetransender: public Ui_filetransender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSENDER_H
