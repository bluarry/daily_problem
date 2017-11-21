#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <QModelIndex>
#include <QTimer>
#include <QTableWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_online_member_list_itemClicked(QTableWidgetItem *item);
    void on_action_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
