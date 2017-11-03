#include "message_loginmistake.h"
#include "ui_message_loginmistake.h"

message_loginMistake::message_loginMistake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message_loginMistake)
{
    ui->setupUi(this);
}

message_loginMistake::~message_loginMistake()
{
    delete ui;
}
