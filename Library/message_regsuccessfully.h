#ifndef MESSAGE_REGSUCCESSFULLY_H
#define MESSAGE_REGSUCCESSFULLY_H

#include <QDialog>

namespace Ui {
class message_regSuccessfully;
}

class message_regSuccessfully : public QDialog
{
    Q_OBJECT

public:
    explicit message_regSuccessfully(QWidget *parent = 0);
    ~message_regSuccessfully();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::message_regSuccessfully *ui;
};

#endif // MESSAGE_REGSUCCESSFULLY_H
