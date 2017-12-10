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
#include <QCryptographichash.h> //md5加密封装类
#include <b_plus_tree.h>


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
    //从用户表查找登录信息
    if(ui->user_option->isChecked() == true)
    {
        int flag = 0,sign = 0;
        QString usrname_input,password_input,md5_password;
        QByteArray bb;
        usrname_input = ui->user_nameInput->text();
        password_input = ui->passwordInput->text();
        const char *username_s = usrname_input.toStdString().data();//Qstring转const char*
        const char *password_s = password_input.toStdString().data();
//        bb = QCryptographicHash::hash ( password_input.toLatin1(), QCryptographicHash::Md5 );
//        md5_password.append(bb.toHex());


        BPlusTree<string> User;
        User.SetTableName(string("User"));;
        User.ReadHead();  //读取文件

        //判断用户名是否已经存在
        Return3 result1 = User.Search(username_s,User.GetRootName());    //!!!!!!!!
        if(result1.Succ)
        {
            flag = 1;
            if(password_input == result1.ve[1].s)
            {
                sign = 1;
                MainWindow *mwins = new MainWindow();//说明mwins指针指向了副窗口，其中MainWindow类在MainWindow.h中定义
                this->hide();//隐藏父窗口，this指针指向父窗口
                mwins->show();
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

    //从管理员表查找信息
    if(ui->administrator_option->isChecked() == true)
    {
        QString adminname_input,password_input,md5_password;
        QByteArray bb;
        adminname_input = ui->user_nameInput->text();
        password_input = ui->passwordInput->text();
        const char *adminname_s = adminname_input.toStdString().data();//Qstring转const char*
        const char *password_s = password_input.toStdString().data();
//        bb = QCryptographicHash::hash ( password_input.toLatin1(), QCryptographicHash::Md5 );
//        md5_password.append(bb.toHex());
        int flag = 0,sign = 0;
        if(adminname_input == "admin")
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
        else if(adminname_input != "admin")
        {
            BPlusTree<string> Admin;
            Admin.SetTableName(string("Admin"));;
            Admin.ReadHead();  //读取文件

            //判断用户名是否已经存在
            Return3 result1 = Admin.Search(adminname_s,Admin.GetRootName());    //!!!!!!!!
            if(result1.Succ)
            {
                flag = 1;
                if(password_input == result1.ve[1].s)
                {
                    sign = 1;
                    MainWindow *mwins = new MainWindow();//说明mwins指针指向了副窗口，其中MainWindow类在MainWindow.h中定义
                    MainWindow_Manage *mwman = new MainWindow_Manage();
                    this->hide();//隐藏父窗口，this指针指向父窗口
                    mwman->show();
                }
            }
        }

            if(flag == 0 && adminname_input != "" && password_input != "")
                QMessageBox::critical(NULL, "critical", "用户名不存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(flag == 1 && sign == 0 && adminname_input != "" && password_input != "")
                QMessageBox::critical(NULL, "critical", "密码错误!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

            if(adminname_input == "")
                QMessageBox::critical(NULL, "critical", "请输入用户名再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            else if(adminname_input != "" && password_input == "")
                QMessageBox::critical(NULL, "critical", "请输入密码再登录!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

