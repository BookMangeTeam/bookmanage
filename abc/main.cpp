#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int register_location = 0;
int manage_jurisdiction = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login loginWin;
    loginWin.show();

    return a.exec();
}
