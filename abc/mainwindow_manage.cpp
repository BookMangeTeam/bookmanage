#include "mainwindow_manage.h"
#include "ui_mainwindow_manage.h"

MainWindow_Manage::MainWindow_Manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Manage)
{
    ui->setupUi(this);
}

MainWindow_Manage::~MainWindow_Manage()
{
    delete ui;
}

void MainWindow_Manage::on_btn_SignupManager_clicked()
{
    //点击管理员注册按钮

}
