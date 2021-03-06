#include "systemmanage.h"
#include "ui_systemmanage.h"
#include "mainwindow_manage.h"
#include <b_plus_tree.h>




SystemManage::SystemManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemManage)
{
    ui->setupUi(this);
}

SystemManage::~SystemManage()
{
    delete ui;
}


void SystemManage::on_oneKeyImport_clicked()
{
    //点击一键导入初始化数据
    ReadData(string("Data2.txt"));

}

void SystemManage::on_oneKeyDelete_clicked()
{
    //点击一键清除数据
    BPlusTree<string> User;
    User.SetTableName("User");
    User.ReadHead();
    User.ClearData();
    BPlusTree<string> Admin;
    Admin.SetTableName("Admin");
    Admin.ReadHead();
    Admin.ClearData();
    BPlusTree<int> Borrow;
    Borrow.SetTableName("Borrow");
    Borrow.ReadHead();
    Borrow.ClearData();
    BPlusTree<int> History;
    History.SetTableName("History");
    History.ReadHead();
    History.ClearData();
    BPlusTree<string> BookB;
    BookB.SetTableName("BookB");
    BookB.ReadHead();
    BookB.ClearData();
    BPlusTree<string> BookA;
    BookA.SetTableName("BookA");
    BookA.ReadHead();
    BookA.ClearData();
    BPlusTree<int> Money;
    Money.SetTableName("Money");
    Money.ReadHead();
    Money.ClearData();
}

void SystemManage::on_returnBtn_clicked()
{
    //返回按钮
    this->hide();
    MainWindow_Manage* mainManageWin = new MainWindow_Manage();
    mainManageWin->show();
}

