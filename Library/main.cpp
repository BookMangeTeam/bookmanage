#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase> //实现数据库连接操作
#include <QSqlQuery>  //执行sql语句
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
