#ifndef REGISTWIN_H
#define REGISTWIN_H

#include <QDialog>

namespace Ui {
class registwin;
}

class registwin : public QDialog
{
    Q_OBJECT

public:
    explicit registwin(QWidget *parent = 0);
    ~registwin();

private slots:
    void on_regist_re_clicked();


    void on_cancel_re_clicked();

private:
    Ui::registwin *ui;
};

#endif // REGISTWIN_H
