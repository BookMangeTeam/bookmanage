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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *mainWindowBackgroundFrame1;
    QPushButton *borrowButton;
    QPushButton *repayButton;
    QPushButton *quitButton;
    QPushButton *renewButton;
    QPushButton *borrowRecordButton;
    QPushButton *moneyBotton;
    QStackedWidget *stackedWidgetPermary;
    QWidget *page;
    QFrame *mainWindowBackGroundFrame2;
    QLabel *name;
    QLineEdit *searchLineEditPermary;
    QPushButton *searchButtonPermary;
    QWidget *page_2;
    QFrame *mainWindowBackGroundFrame3;
    QLineEdit *searchLineEditBorrow;
    QPushButton *searchButtonBorrow;
    QTableView *bookInformationborrow;
    QPushButton *affirmBottonBorrow;
    QPushButton *returnButtonBorrow;
    QWidget *page_3;
    QFrame *mainWindowBackGroundFrame4;
    QTableView *bookInformationRepay;
    QPushButton *affirmBottonRepay;
    QPushButton *returnButtonRepay;
    QWidget *page_4;
    QFrame *mainWindowBackGroundFrame5;
    QTableView *bookInformationRenew;
    QPushButton *affirmBottonRenew;
    QPushButton *returnButtonRenew;
    QWidget *page_5;
    QFrame *mainWindowBackGroundFrame6;
    QTableView *bookInformationBorrowR;
    QPushButton *returnBottonBorrowR;
    QWidget *page_6;
    QFrame *mainWindowBackGroundFrame7;
    QTableView *inDebtInformation;
    QLabel *passwordMoney;
    QTableView *paymentInformation;
    QLineEdit *passwordMoneyInput;
    QPushButton *affirmButtonMoney;
    QPushButton *returnButtonMoney;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1093, 651);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1093, 651));
        MainWindow->setMaximumSize(QSize(1093, 951));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setStyleSheet(QStringLiteral("background-color:#fff"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainWindowBackgroundFrame1 = new QFrame(centralWidget);
        mainWindowBackgroundFrame1->setObjectName(QStringLiteral("mainWindowBackgroundFrame1"));
        mainWindowBackgroundFrame1->setGeometry(QRect(860, 0, 233, 641));
        mainWindowBackgroundFrame1->setAutoFillBackground(false);
        mainWindowBackgroundFrame1->setStyleSheet(QLatin1String("#mainWindowBackgroundFrame1\n"
"{\n"
"border-image: url(:/3.jpg);\n"
"}"));
        mainWindowBackgroundFrame1->setFrameShape(QFrame::StyledPanel);
        mainWindowBackgroundFrame1->setFrameShadow(QFrame::Raised);
        borrowButton = new QPushButton(mainWindowBackgroundFrame1);
        borrowButton->setObjectName(QStringLiteral("borrowButton"));
        borrowButton->setGeometry(QRect(70, 70, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        borrowButton->setFont(font);
        borrowButton->setCursor(QCursor(Qt::PointingHandCursor));
        borrowButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        repayButton = new QPushButton(mainWindowBackgroundFrame1);
        repayButton->setObjectName(QStringLiteral("repayButton"));
        repayButton->setGeometry(QRect(70, 150, 91, 31));
        repayButton->setFont(font);
        repayButton->setCursor(QCursor(Qt::PointingHandCursor));
        repayButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        quitButton = new QPushButton(mainWindowBackgroundFrame1);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(70, 520, 91, 31));
        quitButton->setFont(font);
        quitButton->setCursor(QCursor(Qt::PointingHandCursor));
        quitButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        renewButton = new QPushButton(mainWindowBackgroundFrame1);
        renewButton->setObjectName(QStringLiteral("renewButton"));
        renewButton->setGeometry(QRect(70, 230, 91, 31));
        renewButton->setFont(font);
        renewButton->setCursor(QCursor(Qt::PointingHandCursor));
        renewButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowRecordButton = new QPushButton(mainWindowBackgroundFrame1);
        borrowRecordButton->setObjectName(QStringLiteral("borrowRecordButton"));
        borrowRecordButton->setGeometry(QRect(70, 310, 91, 31));
        borrowRecordButton->setFont(font);
        borrowRecordButton->setCursor(QCursor(Qt::PointingHandCursor));
        borrowRecordButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        moneyBotton = new QPushButton(mainWindowBackgroundFrame1);
        moneyBotton->setObjectName(QStringLiteral("moneyBotton"));
        moneyBotton->setGeometry(QRect(70, 390, 91, 31));
        moneyBotton->setFont(font);
        moneyBotton->setCursor(QCursor(Qt::PointingHandCursor));
        moneyBotton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary = new QStackedWidget(centralWidget);
        stackedWidgetPermary->setObjectName(QStringLiteral("stackedWidgetPermary"));
        stackedWidgetPermary->setGeometry(QRect(0, 0, 861, 641));
        stackedWidgetPermary->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        mainWindowBackGroundFrame2 = new QFrame(page);
        mainWindowBackGroundFrame2->setObjectName(QStringLiteral("mainWindowBackGroundFrame2"));
        mainWindowBackGroundFrame2->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame2->setStyleSheet(QStringLiteral(""));
        mainWindowBackGroundFrame2->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame2->setFrameShadow(QFrame::Raised);
        name = new QLabel(mainWindowBackGroundFrame2);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(170, 120, 521, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(50);
        font1.setBold(true);
        font1.setWeight(75);
        name->setFont(font1);
        name->setAutoFillBackground(false);
        name->setAlignment(Qt::AlignCenter);
        searchLineEditPermary = new QLineEdit(mainWindowBackGroundFrame2);
        searchLineEditPermary->setObjectName(QStringLiteral("searchLineEditPermary"));
        searchLineEditPermary->setGeometry(QRect(150, 330, 541, 41));
        searchLineEditPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonPermary = new QPushButton(mainWindowBackGroundFrame2);
        searchButtonPermary->setObjectName(QStringLiteral("searchButtonPermary"));
        searchButtonPermary->setGeometry(QRect(380, 430, 81, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        searchButtonPermary->setFont(font2);
        searchButtonPermary->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        mainWindowBackGroundFrame3 = new QFrame(page_2);
        mainWindowBackGroundFrame3->setObjectName(QStringLiteral("mainWindowBackGroundFrame3"));
        mainWindowBackGroundFrame3->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame3->setStyleSheet(QStringLiteral(""));
        mainWindowBackGroundFrame3->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame3->setFrameShadow(QFrame::Raised);
        searchLineEditBorrow = new QLineEdit(mainWindowBackGroundFrame3);
        searchLineEditBorrow->setObjectName(QStringLiteral("searchLineEditBorrow"));
        searchLineEditBorrow->setGeometry(QRect(180, 30, 451, 31));
        QFont font3;
        font3.setPointSize(12);
        searchLineEditBorrow->setFont(font3);
        searchLineEditBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonBorrow = new QPushButton(mainWindowBackGroundFrame3);
        searchButtonBorrow->setObjectName(QStringLiteral("searchButtonBorrow"));
        searchButtonBorrow->setGeometry(QRect(670, 30, 71, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        searchButtonBorrow->setFont(font4);
        searchButtonBorrow->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        bookInformationborrow = new QTableView(mainWindowBackGroundFrame3);
        bookInformationborrow->setObjectName(QStringLiteral("bookInformationborrow"));
        bookInformationborrow->setGeometry(QRect(30, 90, 801, 441));
        bookInformationborrow->setStyleSheet(QStringLiteral(""));
        affirmBottonBorrow = new QPushButton(mainWindowBackGroundFrame3);
        affirmBottonBorrow->setObjectName(QStringLiteral("affirmBottonBorrow"));
        affirmBottonBorrow->setGeometry(QRect(740, 550, 91, 31));
        affirmBottonBorrow->setFont(font4);
        affirmBottonBorrow->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonBorrow = new QPushButton(mainWindowBackGroundFrame3);
        returnButtonBorrow->setObjectName(QStringLiteral("returnButtonBorrow"));
        returnButtonBorrow->setGeometry(QRect(30, 550, 91, 31));
        returnButtonBorrow->setFont(font4);
        returnButtonBorrow->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        mainWindowBackGroundFrame4 = new QFrame(page_3);
        mainWindowBackGroundFrame4->setObjectName(QStringLiteral("mainWindowBackGroundFrame4"));
        mainWindowBackGroundFrame4->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame4->setStyleSheet(QStringLiteral(""));
        mainWindowBackGroundFrame4->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame4->setFrameShadow(QFrame::Raised);
        bookInformationRepay = new QTableView(mainWindowBackGroundFrame4);
        bookInformationRepay->setObjectName(QStringLiteral("bookInformationRepay"));
        bookInformationRepay->setGeometry(QRect(20, 60, 811, 461));
        bookInformationRepay->setStyleSheet(QStringLiteral(""));
        affirmBottonRepay = new QPushButton(mainWindowBackGroundFrame4);
        affirmBottonRepay->setObjectName(QStringLiteral("affirmBottonRepay"));
        affirmBottonRepay->setGeometry(QRect(740, 550, 91, 31));
        affirmBottonRepay->setFont(font4);
        affirmBottonRepay->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonRepay->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonRepay = new QPushButton(mainWindowBackGroundFrame4);
        returnButtonRepay->setObjectName(QStringLiteral("returnButtonRepay"));
        returnButtonRepay->setGeometry(QRect(20, 550, 91, 31));
        returnButtonRepay->setFont(font4);
        returnButtonRepay->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonRepay->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        mainWindowBackGroundFrame5 = new QFrame(page_4);
        mainWindowBackGroundFrame5->setObjectName(QStringLiteral("mainWindowBackGroundFrame5"));
        mainWindowBackGroundFrame5->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame5->setStyleSheet(QStringLiteral(""));
        mainWindowBackGroundFrame5->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame5->setFrameShadow(QFrame::Raised);
        bookInformationRenew = new QTableView(mainWindowBackGroundFrame5);
        bookInformationRenew->setObjectName(QStringLiteral("bookInformationRenew"));
        bookInformationRenew->setGeometry(QRect(20, 60, 811, 461));
        bookInformationRenew->setStyleSheet(QStringLiteral(""));
        affirmBottonRenew = new QPushButton(mainWindowBackGroundFrame5);
        affirmBottonRenew->setObjectName(QStringLiteral("affirmBottonRenew"));
        affirmBottonRenew->setGeometry(QRect(740, 550, 91, 31));
        affirmBottonRenew->setFont(font4);
        affirmBottonRenew->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonRenew->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonRenew = new QPushButton(mainWindowBackGroundFrame5);
        returnButtonRenew->setObjectName(QStringLiteral("returnButtonRenew"));
        returnButtonRenew->setGeometry(QRect(20, 550, 91, 31));
        returnButtonRenew->setFont(font4);
        returnButtonRenew->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonRenew->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        mainWindowBackGroundFrame6 = new QFrame(page_5);
        mainWindowBackGroundFrame6->setObjectName(QStringLiteral("mainWindowBackGroundFrame6"));
        mainWindowBackGroundFrame6->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame6->setStyleSheet(QStringLiteral(""));
        mainWindowBackGroundFrame6->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame6->setFrameShadow(QFrame::Raised);
        bookInformationBorrowR = new QTableView(mainWindowBackGroundFrame6);
        bookInformationBorrowR->setObjectName(QStringLiteral("bookInformationBorrowR"));
        bookInformationBorrowR->setGeometry(QRect(20, 60, 811, 461));
        bookInformationBorrowR->setStyleSheet(QStringLiteral(""));
        returnBottonBorrowR = new QPushButton(mainWindowBackGroundFrame6);
        returnBottonBorrowR->setObjectName(QStringLiteral("returnBottonBorrowR"));
        returnBottonBorrowR->setGeometry(QRect(20, 550, 91, 31));
        returnBottonBorrowR->setFont(font4);
        returnBottonBorrowR->setCursor(QCursor(Qt::PointingHandCursor));
        returnBottonBorrowR->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        mainWindowBackGroundFrame7 = new QFrame(page_6);
        mainWindowBackGroundFrame7->setObjectName(QStringLiteral("mainWindowBackGroundFrame7"));
        mainWindowBackGroundFrame7->setGeometry(QRect(0, 0, 861, 641));
        mainWindowBackGroundFrame7->setStyleSheet(QLatin1String("#mainWindowBackGroundFrame7\n"
"{\n"
"	border-image: url(:/6.png);\n"
"}"));
        mainWindowBackGroundFrame7->setFrameShape(QFrame::StyledPanel);
        mainWindowBackGroundFrame7->setFrameShadow(QFrame::Raised);
        inDebtInformation = new QTableView(mainWindowBackGroundFrame7);
        inDebtInformation->setObjectName(QStringLiteral("inDebtInformation"));
        inDebtInformation->setGeometry(QRect(20, 50, 811, 231));
        inDebtInformation->setStyleSheet(QStringLiteral(""));
        passwordMoney = new QLabel(mainWindowBackGroundFrame7);
        passwordMoney->setObjectName(QStringLiteral("passwordMoney"));
        passwordMoney->setGeometry(QRect(600, 360, 121, 31));
        passwordMoney->setFont(font4);
        passwordMoney->setAutoFillBackground(false);
        passwordMoney->setAlignment(Qt::AlignCenter);
        paymentInformation = new QTableView(mainWindowBackGroundFrame7);
        paymentInformation->setObjectName(QStringLiteral("paymentInformation"));
        paymentInformation->setGeometry(QRect(20, 320, 451, 201));
        paymentInformation->setStyleSheet(QStringLiteral(""));
        passwordMoneyInput = new QLineEdit(mainWindowBackGroundFrame7);
        passwordMoneyInput->setObjectName(QStringLiteral("passwordMoneyInput"));
        passwordMoneyInput->setGeometry(QRect(550, 420, 221, 31));
        passwordMoneyInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        passwordMoneyInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        affirmButtonMoney = new QPushButton(mainWindowBackGroundFrame7);
        affirmButtonMoney->setObjectName(QStringLiteral("affirmButtonMoney"));
        affirmButtonMoney->setGeometry(QRect(610, 490, 91, 31));
        affirmButtonMoney->setFont(font4);
        affirmButtonMoney->setCursor(QCursor(Qt::PointingHandCursor));
        affirmButtonMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonMoney = new QPushButton(mainWindowBackGroundFrame7);
        returnButtonMoney->setObjectName(QStringLiteral("returnButtonMoney"));
        returnButtonMoney->setGeometry(QRect(20, 550, 91, 31));
        returnButtonMoney->setFont(font4);
        returnButtonMoney->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_6);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        stackedWidgetPermary->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        borrowButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", Q_NULLPTR));
        repayButton->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", Q_NULLPTR));
        quitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        renewButton->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", Q_NULLPTR));
        borrowRecordButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246\350\256\260\345\275\225", Q_NULLPTR));
        moneyBotton->setText(QApplication::translate("MainWindow", "\347\274\264/\346\254\240\350\264\271", Q_NULLPTR));
        name->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        searchButtonPermary->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        searchLineEditBorrow->setText(QString());
        searchButtonBorrow->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        affirmBottonBorrow->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", Q_NULLPTR));
        returnButtonBorrow->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        affirmBottonRepay->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", Q_NULLPTR));
        returnButtonRepay->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        affirmBottonRenew->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", Q_NULLPTR));
        returnButtonRenew->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        returnBottonBorrowR->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        passwordMoney->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        passwordMoneyInput->setText(QString());
        affirmButtonMoney->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        returnButtonMoney->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
