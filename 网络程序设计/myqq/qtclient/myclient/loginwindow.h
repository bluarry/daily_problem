#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:

    void on_loginin_btn_clicked();

    void on_exit_btn_clicked();

    void on_regist_btn_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
