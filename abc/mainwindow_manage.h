#ifndef MAINWINDOW_MANAGE_H
#define MAINWINDOW_MANAGE_H

#include <QMainWindow>

namespace Ui {
class MainWindow_Manage;
}

class MainWindow_Manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Manage(QWidget *parent = 0);
    ~MainWindow_Manage();

private slots:
    void on_btn_SignupManager_clicked();

private:
    Ui::MainWindow_Manage *ui;
};

#endif // MAINWINDOW_MANAGE_H
