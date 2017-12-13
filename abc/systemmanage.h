#ifndef SYSTEMMANAGE_H
#define SYSTEMMANAGE_H

#include <QWidget>

namespace Ui {
class SystemManage;
}

class SystemManage : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManage(QWidget *parent = 0);
    ~SystemManage();

private slots:


    void on_oneKeyImport_clicked();

    void on_oneKeyDelete_clicked();

    void on_returnBtn_clicked();

private:
    Ui::SystemManage *ui;
};

#endif // SYSTEMMANAGE_H
