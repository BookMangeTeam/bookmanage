#ifndef MESSAGE_LOGINMISTAKE_H
#define MESSAGE_LOGINMISTAKE_H

#include <QDialog>

namespace Ui {
class message_loginMistake;
}

class message_loginMistake : public QDialog
{
    Q_OBJECT

public:
    explicit message_loginMistake(QWidget *parent = 0);
    ~message_loginMistake();

private:
    Ui::message_loginMistake *ui;
};

#endif // MESSAGE_LOGINMISTAKE_H
