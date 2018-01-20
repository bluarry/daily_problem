/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QToolBox *toolBox;
    QWidget *online_member;
    QTableWidget *online_member_list;
    QWidget *offline_member;
    QTableWidget *offline_memeber_list;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(344, 699);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 0, 341, 651));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setFrameShape(QFrame::Box);
        online_member = new QWidget();
        online_member->setObjectName(QString::fromUtf8("online_member"));
        online_member->setGeometry(QRect(0, 0, 339, 579));
        online_member_list = new QTableWidget(online_member);
        if (online_member_list->columnCount() < 1)
            online_member_list->setColumnCount(1);
        QFont font;
        font.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        online_member_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        online_member_list->setObjectName(QString::fromUtf8("online_member_list"));
        online_member_list->setGeometry(QRect(0, 0, 341, 581));
        online_member_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        online_member_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        online_member_list->setDragEnabled(false);
        online_member_list->setSelectionMode(QAbstractItemView::SingleSelection);
        online_member_list->setSelectionBehavior(QAbstractItemView::SelectRows);
        online_member_list->setShowGrid(false);
        online_member_list->horizontalHeader()->setCascadingSectionResizes(false);
        online_member_list->horizontalHeader()->setDefaultSectionSize(351);
        toolBox->addItem(online_member, QString::fromUtf8("\345\234\250\347\272\277"));
        offline_member = new QWidget();
        offline_member->setObjectName(QString::fromUtf8("offline_member"));
        offline_member->setGeometry(QRect(0, 0, 339, 579));
        offline_memeber_list = new QTableWidget(offline_member);
        if (offline_memeber_list->columnCount() < 1)
            offline_memeber_list->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        offline_memeber_list->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        offline_memeber_list->setObjectName(QString::fromUtf8("offline_memeber_list"));
        offline_memeber_list->setGeometry(QRect(0, 0, 341, 581));
        offline_memeber_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        offline_memeber_list->setSelectionMode(QAbstractItemView::SingleSelection);
        offline_memeber_list->setSelectionBehavior(QAbstractItemView::SelectRows);
        offline_memeber_list->setShowGrid(false);
        offline_memeber_list->horizontalHeader()->setDefaultSectionSize(340);
        toolBox->addItem(offline_member, QString::fromUtf8("\347\246\273\347\272\277"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 344, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Myqq", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        action->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = online_member_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(online_member), QApplication::translate("MainWindow", "\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = offline_memeber_list->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(offline_member), QApplication::translate("MainWindow", "\347\246\273\347\272\277", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
