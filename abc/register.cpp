#include "register.h"
#include "ui_register.h"
#include "login.h"
#include <QDebug>
#include <QTextStream>  //文本文件的读写类
#include <QFile>
#include <QRadioButton>
#include <QMessageBox>
#include <global_variable.h>
#include <Qstring>
#include <QCryptographichash.h> //md5加密封装类
#include <b_plus_tree.h>
#include <string.h>
#include <QByteArray>



Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->register_userNameinput->setToolTip("用户名为学号或工号");
    ui->register_passwordInput->setToolTip("密码由数字、字母、特殊符号组成");
    ui->register_passwordAffirmInput->setToolTip("请再次输入密码");
    if(register_location == 1)
    {
        ui->user_optionRegister->setChecked(true);
        ui->administrator_optionRegister->setEnabled(false);
        ui->administrator_optionRegister->setChecked(false);

    }
    if(register_location == 2)
    {
        ui->user_optionRegister->setEnabled(false);
        ui->user_optionRegister->setChecked(false);
        ui->administrator_optionRegister->setChecked(true);
        ui->academyInput->setEnabled(false);
    }
}

Register::~Register()
{
    delete ui;
}

void Register::on_affirmReisterButton_clicked()
{


    std::string md5_password;
    QByteArray bb;
    //注册信息到用户表
    if(register_location == 1)
    {
        QString username,password1,password2,department;
        username = ui->register_userNameinput->text();
        password1 = ui->register_passwordInput->text();
        password2 = ui->register_passwordAffirmInput->text();
        department = ui->academyInput->currentText();
        //username_s = string((const char *)username.toLocal8Bit());!!!!!!!!!!!!
        const char *username_s = username.toStdString().data();//Qstring转const char*
        const char *password_s = password1.toStdString().data();
        const char *department_s = department.toStdString().data();
        string username_fin = username.toStdString();  //将Qstring转化为string类型
        //判断成功情况
        if(username != "" && password1 != "" && password2 != "" && password1 == password2)
        {
            BPlusTree<string> User;
            User.SetTableName(string("User"));
            User.ReadHead();  //读取文件

            //判断用户名是否已经存在
            Return3 result1 = User.Search(username_s,User.GetRootName());    //!!!!!!!!
            if(result1.Succ)
            {
                //用户名已存在
                QMessageBox::critical(this, "critical", "用户名已存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                //将登录信息写进数据库User表
                //密码md5加密
                vector<Undecide>userv;
                Undecide te1, te2, te3, te4;
                strcpy(te1.s,username_s);
                bb = QCryptographicHash::hash ( password1.toLatin1(), QCryptographicHash::Md5 );
                md5_password.append(bb.toHex());
                const char* md5_password_s = md5_password.c_str();
                strcpy(te2.s,md5_password_s);
                strcpy(te3.s,department_s);
                te4.num = 0;
                userv.push_back(te1);
                userv.push_back(te2);
                userv.push_back(te3);
                userv.push_back(te4);;
                User.Insert(username_fin,userv);
                User.SaveHead();//一定要记得保存！
                Login *login = new Login();
                QMessageBox::information(this, "提示", "注册成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                this->hide();
                login->show();
             }
        }

        //判断失败情况
        else
        {
            if(username == "")
            {
                QMessageBox::critical(this, "critical", "请输入用户名!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else if(password1 == "")
            {
                QMessageBox::critical(this, "critical", "请输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else if(password2 == "")
            {
                QMessageBox::critical(this, "critical", "请再次确认输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
                else if(password1 != password2)
            {
                QMessageBox::critical(this, "critical", "两次密码输出不一致!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
        }
    }


    //注册信息到管理员表
    if(register_location == 2)
    {
        QString adminname,password1,password2,department;
        adminname = ui->register_userNameinput->text();
        password1 = ui->register_passwordInput->text();
        password2 = ui->register_passwordAffirmInput->text();
        const char *adminname_s = adminname.toStdString().data();//Qstring转const char*
        const char *password_s = password1.toStdString().data();
        string adminname_fin = adminname.toStdString();  //将Qstring转化为string类型
        //判断成功情况
        if(adminname != "" && password1 != "" && password2 != "" && password1 == password2)
        {
            //判断用户名是否已经存在
            BPlusTree<string> Admin;
            Admin.SetTableName(string("Admin"));
            Admin.ReadHead();  //读取文件

            //判断用户名是否已经存在
            Return3 result1 = Admin.Search(adminname_s,Admin.GetRootName());    //!!!!!!!!
            if(result1.Succ)
            {
                //用户名已存在
                QMessageBox::critical(this, "critical", "用户名已存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                //将登录信息写进数据库User表
                //密码md5加密
                vector<Undecide>userv;
                Undecide te1, te2;
                strcpy(te1.s,adminname_s);
                bb = QCryptographicHash::hash ( password1.toLatin1(), QCryptographicHash::Md5 );
                md5_password.append(bb.toHex());
                const char* md5_password_s = md5_password.c_str();
                strcpy(te2.s,md5_password_s);
                userv.push_back(te1);
                userv.push_back(te2);
                Admin.Insert(adminname_fin,userv);
                Admin.SaveHead();//一定要记得保存！
                Login *login = new Login();
                QMessageBox::information(this, "提示", "注册成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                this->hide();
                login->show();
             }

        }

        //判断失败情况
        else
        {
            if(adminname == "")
            {
                QMessageBox::critical(this, "critical", "请输入用户名!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else if(password1 == "")
            {
                QMessageBox::critical(this, "critical", "请输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else if(password2 == "")
            {
                QMessageBox::critical(this, "critical", "请再次确认输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else if(password1 != password2)
            {
                QMessageBox::critical(this, "critical", "两次密码输出不一致!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }

        }
    }
}
