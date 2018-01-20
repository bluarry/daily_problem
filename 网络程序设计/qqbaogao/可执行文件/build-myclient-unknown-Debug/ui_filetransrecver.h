/********************************************************************************
** Form generated from reading UI file 'filetransrecver.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSRECVER_H
#define UI_FILETRANSRECVER_H

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

class Ui_filetransrecver
{
public:
    QProgressBar *progressBar;
    QPushButton *filetranscancle;
    QLabel *transinfo;
    QPushButton *filetranspause;

    void setupUi(QDialog *filetransrecver)
    {
        if (filetransrecver->objectName().isEmpty())
            filetransrecver->setObjectName(QString::fromUtf8("filetransrecver"));
        filetransrecver->resize(417, 305);
        progressBar = new QProgressBar(filetransrecver);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 130, 381, 51));
        progressBar->setValue(0);
        filetranscancle = new QPushButton(filetransrecver);
        filetranscancle->setObjectName(QString::fromUtf8("filetranscancle"));
        filetranscancle->setGeometry(QRect(250, 220, 131, 51));
        transinfo = new QLabel(filetransrecver);
        transinfo->setObjectName(QString::fromUtf8("transinfo"));
        transinfo->setGeometry(QRect(10, 40, 401, 81));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        transinfo->setFont(font);
        transinfo->setLayoutDirection(Qt::LeftToRight);
        transinfo->setAlignment(Qt::AlignCenter);
        filetranspause = new QPushButton(filetransrecver);
        filetranspause->setObjectName(QString::fromUtf8("filetranspause"));
        filetranspause->setGeometry(QRect(40, 220, 131, 51));

        retranslateUi(filetransrecver);

        QMetaObject::connectSlotsByName(filetransrecver);
    } // setupUi

    void retranslateUi(QDialog *filetransrecver)
    {
        filetransrecver->setWindowTitle(QApplication::translate("filetransrecver", "\346\216\245\346\224\266\347\253\257", 0, QApplication::UnicodeUTF8));
        filetranscancle->setText(QApplication::translate("filetransrecver", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        transinfo->setText(QApplication::translate("filetransrecver", "Wait For Ready", 0, QApplication::UnicodeUTF8));
        filetranspause->setText(QApplication::translate("filetransrecver", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class filetransrecver: public Ui_filetransrecver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSRECVER_H
