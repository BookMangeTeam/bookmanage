#include "message_regsuccessfully.h"
#include "ui_message_regsuccessfully.h"
#include "mainwindow.h"
message_regSuccessfully::message_regSuccessfully(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message_regSuccessfully)
{
    ui->setupUi(this);
}

message_regSuccessfully::~message_regSuccessfully()
{
    delete ui;
}

void message_regSuccessfully::on_pushButton_clicked()
{
    MainWindow *log = new MainWindow(this); //打开登录窗口
    this ->hide();
    log -> show();


}

void message_regSuccessfully::on_pushButton_2_clicked()
{
    QApplication* app;
    this->hide();
    app->exit(0);
}
