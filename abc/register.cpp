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
        ui->administrator_optionRegister->setEnabled(false);
        ui->user_optionRegister->setChecked(true);
        ui->administrator_optionRegister->setChecked(false);

    }
    if(register_location == 2)
    {
        ui->user_optionRegister->setEnabled(false);
        ui->user_optionRegister->setChecked(false);
        ui->administrator_optionRegister->setChecked(true);
    }
}

Register::~Register()
{
    delete ui;
}

void Register::on_affirmReisterButton_clicked()
{

    //注册信息到用户表
    if(register_location == 1)
    {
        QFile f("user.txt");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            qDebug() << "Open failed." << endl;
        }
        else
        {
            QTextStream txtOutput(&f);
            QString username,password1,password2,department;
            username = ui->register_userNameinput->text();
            password1 = ui->register_passwordInput->text();
            password2 = ui->register_passwordAffirmInput->text();
            department = ui->academyInput->currentText();
            //判断成功情况
            if(username != "" && password1 != "" && password2 != "" && password1 == password2)
            {
                //判断用户名是否已经存在
                QString usernameFile;
                int n = 1,an,k = 1,flag = 0;
                QFile f("user.txt");
                if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    qDebug() << "Open failed." << endl;
                }

                else{
                    QTextStream txtInput(&f);
                    while(!txtInput.atEnd())//如果你到了文件的末尾，atEnd()返回真。
                    {
                        usernameFile = txtInput.readLine();//文件读出的用户名
                        an = 4 * n - 3;//用户名在1,5,9....行防止密码和用户名重复导致判断错误
                        if(k == an)
                        {
                            if(username == usernameFile)
                            {
                                QMessageBox::critical(this, "critical", "用户名已存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                                flag = 1;
                                break;
                            }
                            n++;
                        }
                        k++;

                    }
                }
                if(flag == 0)
                {
                    //将登录信息写进磁盘文件
                    txtOutput << username << endl;
                    txtOutput << password1 << endl;
                    txtOutput << password2 << endl;
                    txtOutput << department << endl;
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
        f.close();

    }


    //注册信息到管理员表
    if(register_location == 2)
    {
        QFile f("administrator.txt");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            qDebug() << "Open failed." << endl;
        }
        else
        {
            QTextStream txtOutput(&f);
            QString username,password1,password2,department;
            username = ui->register_userNameinput->text();
            password1 = ui->register_passwordInput->text();
            password2 = ui->register_passwordAffirmInput->text();
            department = ui->academyInput->currentText();
            //判断成功情况
            if(username != "" && password1 != "" && password2 != "" && password1 == password2)
            {

                //判断用户名是否已经存在
                QString usernameFile;
                int n = 1,an,k = 1,flag = 0;
                QFile f("administrator.txt");
                if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    qDebug() << "Open failed." << endl;
                }

                else{
                    QTextStream txtInput(&f);
                    while(!txtInput.atEnd())//如果你到了文件的末尾，atEnd()返回真。
                    {
                        usernameFile = txtInput.readLine();//文件读出的用户名
                        an = 4 * n - 3;
                        if(k == an)
                        {
                            if(username == usernameFile)
                            {
                                QMessageBox::critical(this, "critical", "用户名已存在!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                                flag = 1;
                                break;
                            }
                            n++;
                        }
                        k++;

                    }
                }
                if(flag == 0)
                {
                    //将登录信息写进磁盘文件
                    txtOutput << username << endl;
                    txtOutput << password1 << endl;
                    txtOutput << password2 << endl;
                    txtOutput << department << endl;
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

        f.close();

    }
}
