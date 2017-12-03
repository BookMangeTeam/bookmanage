/********************************************************************************
** Form generated from reading UI file 'mainwindow_manage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_MANAGE_H
#define UI_MAINWINDOW_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Manage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidgetPermary;
    QWidget *page;
    QLabel *name;
    QLineEdit *searchLineEditPermary;
    QPushButton *searchButtonPermary;
    QWidget *page_2;
    QLineEdit *searchLineEditBorrow;
    QPushButton *searchButtonBorrow;
    QTableView *bookInformationborrow;
    QPushButton *affirmBottonBorrow;
    QPushButton *returnButtonBorrow;
    QWidget *page_3;
    QTableView *bookInformationRepay;
    QPushButton *returnButtonRepay;
    QPushButton *affirmBottonRepay;
    QWidget *page_4;
    QTableView *bookInformationRenew;
    QPushButton *returnButtonRenew;
    QPushButton *affirmBottonRenew;
    QWidget *page_5;
    QTableView *bookInformationBorrowR;
    QPushButton *returnBottonBorrowR;
    QWidget *page_6;
    QTableView *inDebtInformation;
    QTableView *paymentInformation;
    QLabel *passwordMoney;
    QLineEdit *passwordMoneyInput;
    QPushButton *affirmButtonMoney;
    QPushButton *returnButtonMoney;
    QPushButton *moneyBotton;
    QPushButton *repayButton;
    QFrame *line;
    QPushButton *quitButton;
    QPushButton *renewButton;
    QPushButton *borrowRecordButton;
    QPushButton *borrowButton;
    QPushButton *btn_SignupManager;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_Manage)
    {
        if (MainWindow_Manage->objectName().isEmpty())
            MainWindow_Manage->setObjectName(QStringLiteral("MainWindow_Manage"));
        MainWindow_Manage->resize(1034, 652);
        MainWindow_Manage->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow_Manage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidgetPermary = new QStackedWidget(centralwidget);
        stackedWidgetPermary->setObjectName(QStringLiteral("stackedWidgetPermary"));
        stackedWidgetPermary->setGeometry(QRect(10, 20, 851, 561));
        stackedWidgetPermary->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        name = new QLabel(page);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(160, 60, 521, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(50);
        font.setBold(false);
        font.setWeight(50);
        name->setFont(font);
        name->setAlignment(Qt::AlignCenter);
        searchLineEditPermary = new QLineEdit(page);
        searchLineEditPermary->setObjectName(QStringLiteral("searchLineEditPermary"));
        searchLineEditPermary->setGeometry(QRect(150, 260, 541, 41));
        searchLineEditPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonPermary = new QPushButton(page);
        searchButtonPermary->setObjectName(QStringLiteral("searchButtonPermary"));
        searchButtonPermary->setGeometry(QRect(390, 330, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        searchButtonPermary->setFont(font1);
        searchButtonPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        searchLineEditBorrow = new QLineEdit(page_2);
        searchLineEditBorrow->setObjectName(QStringLiteral("searchLineEditBorrow"));
        searchLineEditBorrow->setGeometry(QRect(160, 20, 451, 31));
        QFont font2;
        font2.setPointSize(12);
        searchLineEditBorrow->setFont(font2);
        searchLineEditBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonBorrow = new QPushButton(page_2);
        searchButtonBorrow->setObjectName(QStringLiteral("searchButtonBorrow"));
        searchButtonBorrow->setGeometry(QRect(650, 20, 71, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        searchButtonBorrow->setFont(font3);
        searchButtonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        bookInformationborrow = new QTableView(page_2);
        bookInformationborrow->setObjectName(QStringLiteral("bookInformationborrow"));
        bookInformationborrow->setGeometry(QRect(10, 70, 801, 441));
        bookInformationborrow->setStyleSheet(QStringLiteral(""));
        affirmBottonBorrow = new QPushButton(page_2);
        affirmBottonBorrow->setObjectName(QStringLiteral("affirmBottonBorrow"));
        affirmBottonBorrow->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonBorrow->setFont(font3);
        affirmBottonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonBorrow = new QPushButton(page_2);
        returnButtonBorrow->setObjectName(QStringLiteral("returnButtonBorrow"));
        returnButtonBorrow->setGeometry(QRect(10, 530, 91, 31));
        returnButtonBorrow->setFont(font3);
        returnButtonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        bookInformationRepay = new QTableView(page_3);
        bookInformationRepay->setObjectName(QStringLiteral("bookInformationRepay"));
        bookInformationRepay->setGeometry(QRect(0, 40, 811, 461));
        bookInformationRepay->setStyleSheet(QStringLiteral(""));
        returnButtonRepay = new QPushButton(page_3);
        returnButtonRepay->setObjectName(QStringLiteral("returnButtonRepay"));
        returnButtonRepay->setGeometry(QRect(0, 520, 91, 31));
        returnButtonRepay->setFont(font3);
        returnButtonRepay->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        affirmBottonRepay = new QPushButton(page_3);
        affirmBottonRepay->setObjectName(QStringLiteral("affirmBottonRepay"));
        affirmBottonRepay->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonRepay->setFont(font3);
        affirmBottonRepay->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        bookInformationRenew = new QTableView(page_4);
        bookInformationRenew->setObjectName(QStringLiteral("bookInformationRenew"));
        bookInformationRenew->setGeometry(QRect(0, 40, 811, 461));
        bookInformationRenew->setStyleSheet(QStringLiteral(""));
        returnButtonRenew = new QPushButton(page_4);
        returnButtonRenew->setObjectName(QStringLiteral("returnButtonRenew"));
        returnButtonRenew->setGeometry(QRect(0, 520, 91, 31));
        returnButtonRenew->setFont(font3);
        returnButtonRenew->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        affirmBottonRenew = new QPushButton(page_4);
        affirmBottonRenew->setObjectName(QStringLiteral("affirmBottonRenew"));
        affirmBottonRenew->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonRenew->setFont(font3);
        affirmBottonRenew->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        bookInformationBorrowR = new QTableView(page_5);
        bookInformationBorrowR->setObjectName(QStringLiteral("bookInformationBorrowR"));
        bookInformationBorrowR->setGeometry(QRect(0, 40, 811, 461));
        bookInformationBorrowR->setStyleSheet(QStringLiteral(""));
        returnBottonBorrowR = new QPushButton(page_5);
        returnBottonBorrowR->setObjectName(QStringLiteral("returnBottonBorrowR"));
        returnBottonBorrowR->setGeometry(QRect(0, 520, 91, 31));
        returnBottonBorrowR->setFont(font3);
        returnBottonBorrowR->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        inDebtInformation = new QTableView(page_6);
        inDebtInformation->setObjectName(QStringLiteral("inDebtInformation"));
        inDebtInformation->setGeometry(QRect(0, 50, 811, 231));
        inDebtInformation->setStyleSheet(QStringLiteral(""));
        paymentInformation = new QTableView(page_6);
        paymentInformation->setObjectName(QStringLiteral("paymentInformation"));
        paymentInformation->setGeometry(QRect(0, 300, 451, 201));
        paymentInformation->setStyleSheet(QStringLiteral(""));
        passwordMoney = new QLabel(page_6);
        passwordMoney->setObjectName(QStringLiteral("passwordMoney"));
        passwordMoney->setGeometry(QRect(600, 340, 121, 31));
        passwordMoney->setFont(font3);
        passwordMoney->setAlignment(Qt::AlignCenter);
        passwordMoneyInput = new QLineEdit(page_6);
        passwordMoneyInput->setObjectName(QStringLiteral("passwordMoneyInput"));
        passwordMoneyInput->setGeometry(QRect(550, 380, 221, 31));
        passwordMoneyInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        passwordMoneyInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        affirmButtonMoney = new QPushButton(page_6);
        affirmButtonMoney->setObjectName(QStringLiteral("affirmButtonMoney"));
        affirmButtonMoney->setGeometry(QRect(620, 450, 91, 31));
        affirmButtonMoney->setFont(font3);
        affirmButtonMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonMoney = new QPushButton(page_6);
        returnButtonMoney->setObjectName(QStringLiteral("returnButtonMoney"));
        returnButtonMoney->setGeometry(QRect(0, 520, 91, 31));
        returnButtonMoney->setFont(font3);
        returnButtonMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_6);
        moneyBotton = new QPushButton(centralwidget);
        moneyBotton->setObjectName(QStringLiteral("moneyBotton"));
        moneyBotton->setGeometry(QRect(910, 300, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        moneyBotton->setFont(font4);
        moneyBotton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        repayButton = new QPushButton(centralwidget);
        repayButton->setObjectName(QStringLiteral("repayButton"));
        repayButton->setGeometry(QRect(910, 120, 91, 31));
        repayButton->setFont(font4);
        repayButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(860, 10, 20, 591));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(910, 500, 91, 31));
        quitButton->setFont(font4);
        quitButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        renewButton = new QPushButton(centralwidget);
        renewButton->setObjectName(QStringLiteral("renewButton"));
        renewButton->setGeometry(QRect(910, 180, 91, 31));
        renewButton->setFont(font4);
        renewButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowRecordButton = new QPushButton(centralwidget);
        borrowRecordButton->setObjectName(QStringLiteral("borrowRecordButton"));
        borrowRecordButton->setGeometry(QRect(910, 240, 91, 31));
        borrowRecordButton->setFont(font4);
        borrowRecordButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowButton = new QPushButton(centralwidget);
        borrowButton->setObjectName(QStringLiteral("borrowButton"));
        borrowButton->setGeometry(QRect(910, 60, 91, 31));
        borrowButton->setFont(font4);
        borrowButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        btn_SignupManager = new QPushButton(centralwidget);
        btn_SignupManager->setObjectName(QStringLiteral("btn_SignupManager"));
        btn_SignupManager->setGeometry(QRect(910, 360, 93, 28));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font5.setPointSize(12);
        btn_SignupManager->setFont(font5);
        btn_SignupManager->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        MainWindow_Manage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow_Manage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_Manage->setStatusBar(statusbar);

        retranslateUi(MainWindow_Manage);

        stackedWidgetPermary->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow_Manage);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Manage)
    {
        MainWindow_Manage->setWindowTitle(QApplication::translate("MainWindow_Manage", "MainWindow", 0));
        name->setText(QApplication::translate("MainWindow_Manage", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        searchButtonPermary->setText(QApplication::translate("MainWindow_Manage", "\346\220\234\347\264\242", 0));
        searchLineEditBorrow->setText(QString());
        searchButtonBorrow->setText(QApplication::translate("MainWindow_Manage", "\346\220\234\347\264\242", 0));
        affirmBottonBorrow->setText(QApplication::translate("MainWindow_Manage", "\345\200\237\344\271\246", 0));
        returnButtonBorrow->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        returnButtonRepay->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        affirmBottonRepay->setText(QApplication::translate("MainWindow_Manage", "\350\277\230\344\271\246", 0));
        returnButtonRenew->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        affirmBottonRenew->setText(QApplication::translate("MainWindow_Manage", "\347\273\255\345\200\237", 0));
        returnBottonBorrowR->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        passwordMoney->setText(QApplication::translate("MainWindow_Manage", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        passwordMoneyInput->setText(QString());
        affirmButtonMoney->setText(QApplication::translate("MainWindow_Manage", "\347\241\256\350\256\244", 0));
        returnButtonMoney->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        moneyBotton->setText(QApplication::translate("MainWindow_Manage", "\347\274\264/\346\254\240\350\264\271", 0));
        repayButton->setText(QApplication::translate("MainWindow_Manage", "\350\277\230\344\271\246", 0));
        quitButton->setText(QApplication::translate("MainWindow_Manage", "\351\200\200\345\207\272", 0));
        renewButton->setText(QApplication::translate("MainWindow_Manage", "\347\273\255\345\200\237", 0));
        borrowRecordButton->setText(QApplication::translate("MainWindow_Manage", "\345\200\237\344\271\246\350\256\260\345\275\225", 0));
        borrowButton->setText(QApplication::translate("MainWindow_Manage", "\345\200\237\344\271\246", 0));
        btn_SignupManager->setText(QApplication::translate("MainWindow_Manage", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Manage: public Ui_MainWindow_Manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MANAGE_H
