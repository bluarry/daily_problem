/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLineEdit *in_username;
    QLineEdit *in_password;
    QLabel *label_username;
    QLabel *label_password;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginin_btn;
    QPushButton *regist_btn;
    QPushButton *exit_btn;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(419, 305);
        in_username = new QLineEdit(LoginWindow);
        in_username->setObjectName(QString::fromUtf8("in_username"));
        in_username->setGeometry(QRect(160, 70, 191, 41));
        in_password = new QLineEdit(LoginWindow);
        in_password->setObjectName(QString::fromUtf8("in_password"));
        in_password->setGeometry(QRect(160, 140, 191, 41));
        in_password->setEchoMode(QLineEdit::Password);
        label_username = new QLabel(LoginWindow);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(60, 70, 81, 31));
        QFont font;
        font.setPointSize(16);
        label_username->setFont(font);
        label_password = new QLabel(LoginWindow);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(70, 150, 63, 20));
        label_password->setFont(font);
        horizontalLayoutWidget = new QWidget(LoginWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 210, 381, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 10, 5, 5);
        loginin_btn = new QPushButton(horizontalLayoutWidget);
        loginin_btn->setObjectName(QString::fromUtf8("loginin_btn"));
        loginin_btn->setFont(font);

        horizontalLayout->addWidget(loginin_btn);

        regist_btn = new QPushButton(horizontalLayoutWidget);
        regist_btn->setObjectName(QString::fromUtf8("regist_btn"));
        regist_btn->setFont(font);

        horizontalLayout->addWidget(regist_btn);

        exit_btn = new QPushButton(horizontalLayoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setFont(font);

        horizontalLayout->addWidget(exit_btn);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_username->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215: ", 0, QApplication::UnicodeUTF8));
        label_password->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201:", 0, QApplication::UnicodeUTF8));
        loginin_btn->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        regist_btn->setText(QApplication::translate("LoginWindow", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        exit_btn->setText(QApplication::translate("LoginWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
