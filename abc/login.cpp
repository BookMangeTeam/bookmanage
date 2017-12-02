#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "mainwindow.h"
#include "mainwindow_manage.h"
#include "ui_mainwindow_manage.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextStream>  //文本文件的读写类
#include <QFile>
#include <QMessageBox>
#include <global_variable.h>


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->user_nameInput->setToolTip("请输入用户名");
    ui->passwordInput->setToolTip("请输入密码");
}

Login::~Login()
{
    delete ui;
}

void Login::on_registerButton_clicked()
{
    register_location = 1;
    Register *reg = new Register();//说明reg指针指向了副窗口，其中Register类在register中定义
    this->hide();//隐藏父窗口，this指针指向父窗口
    reg->show();

}




void Login::on_loginButton_clicked()
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
                        MainWindow *mwins = new MainWindow();//说明main_i指针指向了副窗口，其中main_interface类在main_interface.h中定义
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
    if(ui->administrator_option->isChecked() == true)
    {
        int flag = 0,sign = 0;
        if(usrname_input == "admin")
        {
            flag = 1;
            if(password_input == "system123")
            {
                sign = 1;
                MainWindow_Manage *mwins_mag = new MainWindow_Manage();  //指向超级管理员窗口
                this->hide();
                mwins_mag->show();
            }
        }
        else if(usrname_input != "admin")
        {
             QFile f("administrator.txt");
             if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
             {
                qDebug() << "Open failed." << endl;
             }
             else
             {
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
                            MainWindow_Manage *mwins_mag = new MainWindow_Manage();  //指向管理员窗口
                            this->hide();
                            mwins_mag->show();
                            break;
                        }
                    }
                }
             }
             f.close();
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
}

