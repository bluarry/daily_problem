/********************************************************************************
** Form generated from reading UI file 'registwin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTWIN_H
#define UI_REGISTWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registwin
{
public:
    QPushButton *regist_re;
    QPushButton *cancel_re;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username_edit;
    QLineEdit *userpasswd;

    void setupUi(QDialog *registwin)
    {
        if (registwin->objectName().isEmpty())
            registwin->setObjectName(QString::fromUtf8("registwin"));
        registwin->resize(440, 333);
        regist_re = new QPushButton(registwin);
        regist_re->setObjectName(QString::fromUtf8("regist_re"));
        regist_re->setGeometry(QRect(70, 250, 131, 51));
        QFont font;
        font.setPointSize(16);
        regist_re->setFont(font);
        cancel_re = new QPushButton(registwin);
        cancel_re->setObjectName(QString::fromUtf8("cancel_re"));
        cancel_re->setGeometry(QRect(240, 250, 131, 51));
        cancel_re->setFont(font);
        label = new QLabel(registwin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 81, 41));
        label->setFont(font);
        label_2 = new QLabel(registwin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 160, 51, 31));
        label_2->setFont(font);
        username_edit = new QLineEdit(registwin);
        username_edit->setObjectName(QString::fromUtf8("username_edit"));
        username_edit->setGeometry(QRect(170, 80, 191, 41));
        userpasswd = new QLineEdit(registwin);
        userpasswd->setObjectName(QString::fromUtf8("userpasswd"));
        userpasswd->setGeometry(QRect(170, 160, 191, 41));
        userpasswd->setEchoMode(QLineEdit::Password);

        retranslateUi(registwin);

        QMetaObject::connectSlotsByName(registwin);
    } // setupUi

    void retranslateUi(QDialog *registwin)
    {
        registwin->setWindowTitle(QApplication::translate("registwin", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        regist_re->setText(QApplication::translate("registwin", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        cancel_re->setText(QApplication::translate("registwin", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("registwin", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("registwin", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class registwin: public Ui_registwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTWIN_H
