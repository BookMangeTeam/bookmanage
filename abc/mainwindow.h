#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_borrowButton_clicked();

    void on_returnButtonBorrow_clicked();


    void on_returnButtonRepay_clicked();

    void on_repayButton_clicked();

    void on_renewButton_clicked();

    void on_returnButtonRenew_clicked();

    void on_borrowRecordButton_clicked();

    void on_returnBottonBorrowR_clicked();

    void on_moneyBotton_clicked();

    void on_returnButtonMoney_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
