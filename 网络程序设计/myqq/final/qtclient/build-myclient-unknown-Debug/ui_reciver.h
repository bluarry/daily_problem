/********************************************************************************
** Form generated from reading UI file 'reciver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIVER_H
#define UI_RECIVER_H

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

class Ui_Reciver
{
public:
    QLabel *transinfo;
    QPushButton *filetranscancle;
    QProgressBar *progressBar;
    QPushButton *filetranspause;

    void setupUi(QDialog *Reciver)
    {
        if (Reciver->objectName().isEmpty())
            Reciver->setObjectName(QString::fromUtf8("Reciver"));
        Reciver->resize(400, 300);
        transinfo = new QLabel(Reciver);
        transinfo->setObjectName(QString::fromUtf8("transinfo"));
        transinfo->setGeometry(QRect(0, 30, 401, 81));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        transinfo->setFont(font);
        transinfo->setLayoutDirection(Qt::LeftToRight);
        transinfo->setAlignment(Qt::AlignCenter);
        filetranscancle = new QPushButton(Reciver);
        filetranscancle->setObjectName(QString::fromUtf8("filetranscancle"));
        filetranscancle->setGeometry(QRect(220, 230, 131, 51));
        progressBar = new QProgressBar(Reciver);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 130, 381, 51));
        progressBar->setValue(0);
        filetranspause = new QPushButton(Reciver);
        filetranspause->setObjectName(QString::fromUtf8("filetranspause"));
        filetranspause->setGeometry(QRect(50, 230, 131, 51));

        retranslateUi(Reciver);

        QMetaObject::connectSlotsByName(Reciver);
    } // setupUi

    void retranslateUi(QDialog *Reciver)
    {
        Reciver->setWindowTitle(QApplication::translate("Reciver", "Dialog", 0, QApplication::UnicodeUTF8));
        transinfo->setText(QApplication::translate("Reciver", "Wait For Ready", 0, QApplication::UnicodeUTF8));
        filetranscancle->setText(QApplication::translate("Reciver", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        filetranspause->setText(QApplication::translate("Reciver", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Reciver: public Ui_Reciver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIVER_H
