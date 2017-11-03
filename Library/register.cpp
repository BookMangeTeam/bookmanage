#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "message_regsuccessfully.h"
#include <QDebug>
#include <QTextStream>  //文本文件的读写类
#include <QFile>
#include <QRadioButton>
#include <QMessageBox>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->register_userNameinput->setToolTip("用户名为11位纯数字学号或8位纯数字工号");
    ui->register_passwordInput->setToolTip("密码由数字、字母、特殊符号组成");
    ui->register_passwordAffirmInput->setToolTip("请再次输入密码");
}

Register::~Register()
{
    delete ui;
}



void Register::on_affirmReisterButton_clicked()
{
    //注册信息到用户表
    if(ui->user_optionRegister->isChecked() == true)
    {
        int flag = 0;
        QFile f("user.txt");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            qDebug() << "Open failed." << endl;
        }
        else{
            QTextStream txtOutput(&f);
            QString username,password1,password2,department;
            username = ui->register_userNameinput->text();
            password1 = ui->register_passwordInput->text();
            password2 = ui->register_passwordAffirmInput->text();
            if(username == "" && password1 !="" && password2 != "")
            {
                QMessageBox::critical(NULL, "critical", "请输入用户名!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 =="" && password2 == "")
            {
                QMessageBox::critical(NULL, "critical", "请输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 !="" && password2 == "")
            {
                QMessageBox::critical(NULL, "critical", "请输入确认密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username == "" && password1 =="" && password2 == "")
            {
                QMessageBox::warning(NULL, "critical", "请输入用户名和密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 !="" && password2 != "" && password1 != password2)
            {
                QMessageBox::critical(NULL, "critical", "两次密码不一致!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            department = ui->academyInput->currentText();
            txtOutput << username << endl;
            if(password1 == password2)
            {
                txtOutput << password1 << endl;
                txtOutput << password2 << endl;
                txtOutput << department << endl;
            }
            if(flag == 0)
            {
                message_regSuccessfully *mes_regS = new message_regSuccessfully(this);
                this->hide();
                mes_regS->show();
            }
        }
        f.close();
    }


    //注册信息到管理员表
    if(ui->administrator_optionRegister->isChecked() == true)
    {
        int flag = 0;
        QFile f("administrator.txt");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            qDebug() << "Open failed." << endl;
        }
        else{
            QTextStream txtOutput(&f);
            QString username,password1,password2,department;
            username = ui->register_userNameinput->text();
            password1 = ui->register_passwordInput->text();
            password2 = ui->register_passwordAffirmInput->text();
            if(username == "" && password1 !="" && password2 != "")
            {
                QMessageBox::critical(NULL, "critical", "请输入用户名!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 =="" && password2 == "")
            {
                QMessageBox::critical(NULL, "critical", "请输入密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 !="" && password2 == "")
            {
                QMessageBox::critical(NULL, "critical", "请输入确认密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username == "" && password1 =="" && password2 == "")
            {
                QMessageBox::warning(NULL, "critical", "请输入用户名和密码!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            else if(username != "" && password1 !="" && password2 != "" && password1 != password2)
            {
                QMessageBox::critical(NULL, "critical", "两次密码不一致!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                flag = 1;
            }
            department = ui->academyInput->currentText();
            txtOutput << username << endl;
            if(password1 == password2)
            {
                txtOutput << password1 << endl;
                txtOutput << password2 << endl;
                txtOutput << department << endl;
            }
            if(flag == 0)
            {
                message_regSuccessfully *mes_regS = new message_regSuccessfully(this);
                this->hide();
                mes_regS->show();
            }
        }
        f.close();
    }
}
