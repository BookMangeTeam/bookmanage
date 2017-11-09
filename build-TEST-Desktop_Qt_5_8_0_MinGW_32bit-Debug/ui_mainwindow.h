/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *borrowButton;
    QPushButton *repayButton;
    QPushButton *renewButton;
    QPushButton *borrowRecordButton;
    QPushButton *quitButton;
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
    QLabel *paymentAmount;
    QLineEdit *paymentAmountInput;
    QLabel *passwordMoney;
    QLineEdit *passwordMoneyInput;
    QPushButton *affirmButtonMoney;
    QPushButton *returnButtonMoney;
    QFrame *line;
    QPushButton *moneyBotton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1034, 632);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QStringLiteral("background-color:#fff"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        borrowButton = new QPushButton(centralWidget);
        borrowButton->setObjectName(QStringLiteral("borrowButton"));
        borrowButton->setGeometry(QRect(910, 50, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        borrowButton->setFont(font);
        borrowButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        repayButton = new QPushButton(centralWidget);
        repayButton->setObjectName(QStringLiteral("repayButton"));
        repayButton->setGeometry(QRect(910, 110, 91, 31));
        repayButton->setFont(font);
        repayButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        renewButton = new QPushButton(centralWidget);
        renewButton->setObjectName(QStringLiteral("renewButton"));
        renewButton->setGeometry(QRect(910, 170, 91, 31));
        renewButton->setFont(font);
        renewButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowRecordButton = new QPushButton(centralWidget);
        borrowRecordButton->setObjectName(QStringLiteral("borrowRecordButton"));
        borrowRecordButton->setGeometry(QRect(910, 230, 91, 31));
        borrowRecordButton->setFont(font);
        borrowRecordButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(910, 490, 91, 31));
        quitButton->setFont(font);
        quitButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary = new QStackedWidget(centralWidget);
        stackedWidgetPermary->setObjectName(QStringLiteral("stackedWidgetPermary"));
        stackedWidgetPermary->setGeometry(QRect(10, 10, 851, 571));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        name = new QLabel(page);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(160, 60, 521, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(50);
        font1.setBold(false);
        font1.setWeight(50);
        name->setFont(font1);
        name->setAlignment(Qt::AlignCenter);
        searchLineEditPermary = new QLineEdit(page);
        searchLineEditPermary->setObjectName(QStringLiteral("searchLineEditPermary"));
        searchLineEditPermary->setGeometry(QRect(150, 260, 541, 41));
        searchLineEditPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonPermary = new QPushButton(page);
        searchButtonPermary->setObjectName(QStringLiteral("searchButtonPermary"));
        searchButtonPermary->setGeometry(QRect(390, 330, 81, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        searchButtonPermary->setFont(font2);
        searchButtonPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page);
        name->raise();
        searchLineEditPermary->raise();
        searchButtonPermary->raise();
        quitButton->raise();
        borrowButton->raise();
        renewButton->raise();
        borrowRecordButton->raise();
        repayButton->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        searchLineEditBorrow = new QLineEdit(page_2);
        searchLineEditBorrow->setObjectName(QStringLiteral("searchLineEditBorrow"));
        searchLineEditBorrow->setGeometry(QRect(160, 20, 451, 31));
        QFont font3;
        font3.setPointSize(12);
        searchLineEditBorrow->setFont(font3);
        searchButtonBorrow = new QPushButton(page_2);
        searchButtonBorrow->setObjectName(QStringLiteral("searchButtonBorrow"));
        searchButtonBorrow->setGeometry(QRect(650, 20, 71, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        searchButtonBorrow->setFont(font4);
        bookInformationborrow = new QTableView(page_2);
        bookInformationborrow->setObjectName(QStringLiteral("bookInformationborrow"));
        bookInformationborrow->setGeometry(QRect(10, 70, 801, 441));
        affirmBottonBorrow = new QPushButton(page_2);
        affirmBottonBorrow->setObjectName(QStringLiteral("affirmBottonBorrow"));
        affirmBottonBorrow->setGeometry(QRect(720, 530, 91, 31));
        affirmBottonBorrow->setFont(font4);
        returnButtonBorrow = new QPushButton(page_2);
        returnButtonBorrow->setObjectName(QStringLiteral("returnButtonBorrow"));
        returnButtonBorrow->setGeometry(QRect(10, 530, 91, 31));
        returnButtonBorrow->setFont(font4);
        stackedWidgetPermary->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        bookInformationRepay = new QTableView(page_3);
        bookInformationRepay->setObjectName(QStringLiteral("bookInformationRepay"));
        bookInformationRepay->setGeometry(QRect(0, 40, 811, 461));
        returnButtonRepay = new QPushButton(page_3);
        returnButtonRepay->setObjectName(QStringLiteral("returnButtonRepay"));
        returnButtonRepay->setGeometry(QRect(0, 520, 91, 31));
        returnButtonRepay->setFont(font4);
        affirmBottonRepay = new QPushButton(page_3);
        affirmBottonRepay->setObjectName(QStringLiteral("affirmBottonRepay"));
        affirmBottonRepay->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonRepay->setFont(font4);
        stackedWidgetPermary->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        bookInformationRenew = new QTableView(page_4);
        bookInformationRenew->setObjectName(QStringLiteral("bookInformationRenew"));
        bookInformationRenew->setGeometry(QRect(0, 40, 811, 461));
        returnButtonRenew = new QPushButton(page_4);
        returnButtonRenew->setObjectName(QStringLiteral("returnButtonRenew"));
        returnButtonRenew->setGeometry(QRect(0, 520, 91, 31));
        returnButtonRenew->setFont(font4);
        affirmBottonRenew = new QPushButton(page_4);
        affirmBottonRenew->setObjectName(QStringLiteral("affirmBottonRenew"));
        affirmBottonRenew->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonRenew->setFont(font4);
        stackedWidgetPermary->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        bookInformationBorrowR = new QTableView(page_5);
        bookInformationBorrowR->setObjectName(QStringLiteral("bookInformationBorrowR"));
        bookInformationBorrowR->setGeometry(QRect(0, 40, 811, 461));
        returnBottonBorrowR = new QPushButton(page_5);
        returnBottonBorrowR->setObjectName(QStringLiteral("returnBottonBorrowR"));
        returnBottonBorrowR->setGeometry(QRect(0, 520, 91, 31));
        returnBottonBorrowR->setFont(font4);
        stackedWidgetPermary->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        inDebtInformation = new QTableView(page_6);
        inDebtInformation->setObjectName(QStringLiteral("inDebtInformation"));
        inDebtInformation->setGeometry(QRect(0, 50, 811, 231));
        paymentInformation = new QTableView(page_6);
        paymentInformation->setObjectName(QStringLiteral("paymentInformation"));
        paymentInformation->setGeometry(QRect(0, 300, 451, 201));
        paymentAmount = new QLabel(page_6);
        paymentAmount->setObjectName(QStringLiteral("paymentAmount"));
        paymentAmount->setGeometry(QRect(480, 320, 121, 31));
        paymentAmount->setFont(font4);
        paymentAmount->setAlignment(Qt::AlignCenter);
        paymentAmountInput = new QLineEdit(page_6);
        paymentAmountInput->setObjectName(QStringLiteral("paymentAmountInput"));
        paymentAmountInput->setGeometry(QRect(640, 320, 113, 31));
        passwordMoney = new QLabel(page_6);
        passwordMoney->setObjectName(QStringLiteral("passwordMoney"));
        passwordMoney->setGeometry(QRect(490, 400, 71, 31));
        passwordMoney->setFont(font4);
        passwordMoney->setAlignment(Qt::AlignCenter);
        passwordMoneyInput = new QLineEdit(page_6);
        passwordMoneyInput->setObjectName(QStringLiteral("passwordMoneyInput"));
        passwordMoneyInput->setGeometry(QRect(590, 400, 221, 31));
        passwordMoneyInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        affirmButtonMoney = new QPushButton(page_6);
        affirmButtonMoney->setObjectName(QStringLiteral("affirmButtonMoney"));
        affirmButtonMoney->setGeometry(QRect(720, 470, 91, 31));
        affirmButtonMoney->setFont(font4);
        returnButtonMoney = new QPushButton(page_6);
        returnButtonMoney->setObjectName(QStringLiteral("returnButtonMoney"));
        returnButtonMoney->setGeometry(QRect(0, 520, 91, 31));
        returnButtonMoney->setFont(font4);
        stackedWidgetPermary->addWidget(page_6);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(860, 0, 20, 591));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        moneyBotton = new QPushButton(centralWidget);
        moneyBotton->setObjectName(QStringLiteral("moneyBotton"));
        moneyBotton->setGeometry(QRect(910, 290, 91, 31));
        moneyBotton->setFont(font);
        moneyBotton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidgetPermary->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        borrowButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", Q_NULLPTR));
        repayButton->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", Q_NULLPTR));
        renewButton->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", Q_NULLPTR));
        borrowRecordButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246\350\256\260\345\275\225", Q_NULLPTR));
        quitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        name->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        searchButtonPermary->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        searchLineEditBorrow->setText(QString());
        searchButtonBorrow->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        affirmBottonBorrow->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", Q_NULLPTR));
        returnButtonBorrow->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        returnButtonRepay->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        affirmBottonRepay->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", Q_NULLPTR));
        returnButtonRenew->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        affirmBottonRenew->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", Q_NULLPTR));
        returnBottonBorrowR->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        paymentAmount->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\274\264\350\264\271\351\207\221\351\242\235", Q_NULLPTR));
        passwordMoney->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        passwordMoneyInput->setText(QString());
        affirmButtonMoney->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        returnButtonMoney->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        moneyBotton->setText(QApplication::translate("MainWindow", "\347\274\264/\346\254\240\350\264\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
