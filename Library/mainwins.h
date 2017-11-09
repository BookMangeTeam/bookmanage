#ifndef MAINWINS_H
#define MAINWINS_H

#include <QWidget>

namespace Ui {
class MainWins;
}

class MainWins : public QWidget
{
    Q_OBJECT

public:
    explicit MainWins(QWidget *parent = 0);
    ~MainWins();

private slots:
    void on_search_btn_clicked();

private:
    Ui::MainWins *ui;
};

#endif // MAINWINS_H
