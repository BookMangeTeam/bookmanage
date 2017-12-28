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
    ui->register_userNameinput->setPlaceholderText("用户名为6~20位数字或字母组成");
    ui->register_passwordInput->setPlaceholderText("6~20位数字字母特殊符号任意2或3种");
    ui->register_passwordAffirmInput->setPlaceholderText("请再次输入密码");
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
            QRegExp username_reg_exp("^[0-9a-zA-Z]{6,20}$");
            QRegExpValidator *username_validator = new QRegExpValidator(username_reg_exp);
            if(!username_validator->regExp().exactMatch(username))
            {
               QMessageBox::critical(this, "critical", "用户名不符合规范!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                QRegExp password_reg_exp("^^(?![\d]+$)(?![a-zA-Z]+$)(?![^\da-zA-Z]+$).{6,20}$");
                QRegExpValidator *password_validator = new QRegExpValidator(password_reg_exp);
                if(!password_validator->regExp().exactMatch(password1))
                {
                   QMessageBox::critical(this, "critical", "密码不符合规范!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                }
                else
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
                        Undecide te1, te2, te3, te4,te5;
                        strcpy(te1.s,username_s);
                        bb = QCryptographicHash::hash ( password1.toLatin1(), QCryptographicHash::Md5 );
                        md5_password.append(bb.toHex());
                        const char* md5_password_s = md5_password.c_str();
                        strcpy(te2.s,md5_password_s);
                        strcpy(te3.s,department_s);
                        te4.dou = 0;
                        te5.num = 0;
                        userv.push_back(te1);
                        userv.push_back(te2);
                        userv.push_back(te3);
                        userv.push_back(te4);
                        userv.push_back(te5);
                        User.Insert(username_fin,userv);
                        User.SaveHead();//一定要记得保存！
                        Login *login = new Login();
                        QMessageBox::information(this, "提示", "注册成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                        this->hide();
                        login->show();
                     }
                }
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
            QRegExp adminname_reg_exp("^[0-9a-zA-Z]{6,20}$");
            QRegExpValidator *adminname_validator = new QRegExpValidator(adminname_reg_exp);
            if(!adminname_validator->regExp().exactMatch(adminname))
            {
               QMessageBox::critical(this, "critical", "用户名不符合规范!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            }
            else
            {
                QRegExp password_reg_exp1("^^(?![\d]+$)(?![a-zA-Z]+$)(?![^\da-zA-Z]+$).{6,20}$");
                QRegExpValidator *password_validator1 = new QRegExpValidator(password_reg_exp1);
                if(!password_validator1->regExp().exactMatch(password1))
                {
                   QMessageBox::critical(this, "critical", "密码不符合规范!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                }
                else
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
                        //将登录信息写进数据库admin表
                        //密码md5加密
                        vector<Undecide>userv;
                        Undecide te1, te2;
                        strcpy(te1.s,adminname_s);
                        bb = QCryptographicHash::hash ( password1.toLatin1(), QCryptographicHash::Md5 );
                        md5_password.append(bb.toHex());
                        const char* md5_password_s = md5_password.c_str();
                        strcpy(te2.s,md5_password_s);
                        //userv.push_back(te1);
                        userv.push_back(te2);
                        Admin.Insert(adminname_fin,userv);
                        Admin.SaveHead();//一定要记得保存！
                        Login *login = new Login();
                        QMessageBox::information(this, "提示", "注册成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                        this->hide();
                        login->show();
                     }

                }
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
