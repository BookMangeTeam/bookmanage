#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "mainwins.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextStream>  //文本文件的读写类
#include <QFile>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QSqlDatabase data_base = QSqlDatabase::addDatabase("QMYSQL");
//    data_base.setHostName("localhost");  //设置主机地址
//    data_base.setPort(3306);  //设置端口
//    data_base.setDatabaseName("student");  //设置数据库名称
//    data_base.setUserName("root");  //设置用户名
//    data_base.setPassword("sc1997217");  //设置密码
//    if(!data_base.open())
//        qDebug()<<"failed to connect to mysql";
//    else
//        qDebug()<<"success";
     ui->user_nameInput->setToolTip("请输入用户名");
     ui->passwordInput->setToolTip("请输入密码");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registerButton_clicked()
{
    Register *reg = new Register(this);//说明reg指针指向了副窗口，其中Register类在register中定义
    this->hide();//隐藏父窗口，this指针指向父窗口
    reg->show();

}




void MainWindow::on_loginButton_clicked()
{
    QString username,password, usrname_input,password_input;
    usrname_input = ui->user_nameInput->text();
    password_input = ui->passwordInput->text();
    //从用户表查找登录信息
    if(ui->user_option->isChecked() == true){
        int flag = 0,sign = 0;
        QFile f("user.txt");
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Open failed." << endl;
        }

        else{
            QTextStream txtInput(&f);
            while(!txtInput.atEnd())//如果你到了文件的末尾，atEnd()返回真。
            {
                username = txtInput.readLine();//文件读出的用户名
                if(usrname_input == username)//验证用户名
                {
                    flag = 1;
                    password = txtInput.readLine();
                    if(password_input == password)//验证密码
                    {
                        sign = 1;
                        MainWins *mwins = new MainWins();//说明main_i指针指向了副窗口，其中main_interface类在main_interface.h中定义
                        this->hide();//隐藏父窗口，this指针指向父窗口
                        mwins->show();
                        break;
                    }
                }
            }
            if(flag == 0 && usrname_input != "" && password_input != "")
                QMessageBox::critical(this, "critical", "用户名不存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(flag == 1 && sign == 0 && usrname_input != "" && password_input != "")
                QMessageBox::critical(this, "critical", "密码错误!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            if(usrname_input == "")
                QMessageBox::critical(this, "critical", "请输入用户名再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(usrname_input != "" && password_input == "")
                QMessageBox::critical(this, "critical", "请输入密码再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        }
        f.close();
    }

    //从管理员表查找信息
    if(ui->administrator_option->isChecked() == true){
        int flag = 0,sign = 0;
        QFile f("administrator.txt");
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Open failed." << endl;
        }

        else{
            QTextStream txtInput(&f);
            while(!txtInput.atEnd())//如果你到了文件的末尾，atEnd()返回真。
            {
                username = txtInput.readLine();
                if(usrname_input == username)
                {
                    flag = 1;
                    password = txtInput.readLine();
                    if(password_input == password)
                    {
                        sign = 1;
                        MainWins *mwins = new MainWins();//说明main_i指针指向了副窗口，其中main_interface类在main_interface.h中定义
                        this->hide();//隐藏父窗口，this指针指向父窗口
                        mwins->show();
                        break;
                    }
                }
            }
            if(flag == 0 && usrname_input != "" && password_input != "")
                QMessageBox::critical(NULL, "critical", "用户名不存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(flag == 1 && sign == 0 && usrname_input != "" && password_input != "")
                QMessageBox::critical(NULL, "critical", "密码错误!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            if(usrname_input == "")
                QMessageBox::critical(NULL, "critical", "请输入用户名再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(usrname_input != "" && password_input == "")
                QMessageBox::critical(NULL, "critical", "请输入密码再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
        f.close();
    }
}
