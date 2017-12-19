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

    void on_addButton_clicked();

    void on_returnButtonAdd_clicked();

    void on_deleteButton_clicked();

    void on_returnButtonDelate_clicked();

    void on_updateButton_clicked();

    void on_returnButtonUpdate_clicked();

    void on_borrowRecordButtonManage_clicked();

    void on_returnBottonBRManage_clicked();

    void on_affirmBottonAdd_clicked();

    void on_affirmBottonDelate_clicked();

    void on_btn_manageSystem_clicked();

    void on_affirmBottonUpdate_clicked();

    void on_searchButtonUpdate_clicked();

    void on_searchButtonDelate_clicked();

    void on_quitButtonManage_clicked();

private:
    Ui::MainWindow_Manage *ui;
};

#endif // MAINWINDOW_MANAGE_H
