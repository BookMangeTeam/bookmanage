/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidgetPermary;
    QWidget *page;
    QLabel *name;
    QLineEdit *searchLineEditPermary;
    QPushButton *searchButtonPermary;
    QRadioButton *bookName_search;
    QRadioButton *author_search;
    QRadioButton *isbn_search;
    QRadioButton *bookNumber_search;
    QWidget *page_2;
    QFrame *mainWindowBackGroundFrame3;
    QLineEdit *searchLineEditBorrow;
    QPushButton *searchButtonBorrow;
    QTableView *bookInformationborrow;
    QPushButton *affirmBottonBorrow;
    QPushButton *returnButtonBorrow;
    QRadioButton *bookNameBorrow_search;
    QRadioButton *authorBorrow_search;
    QRadioButton *isbnBorrow_search;
    QRadioButton *bookNumberBorrow_search;
    QTableView *hasBeenBorrow;
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
    QPushButton *payMoney;
    QPushButton *returnButtonMoney;
    QPushButton *quitButton;
    QPushButton *renewButton;
    QPushButton *repayButton;
    QPushButton *borrowRecordButton;
    QPushButton *borrowButton;
    QPushButton *moneyBotton;
    QFrame *line;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1093, 656);
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
        stackedWidgetPermary = new QStackedWidget(centralWidget);
        stackedWidgetPermary->setObjectName(QStringLiteral("stackedWidgetPermary"));
        stackedWidgetPermary->setGeometry(QRect(10, 0, 851, 661));
        stackedWidgetPermary->setStyleSheet(QStringLiteral("background:#fff"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        name = new QLabel(page);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(170, 100, 521, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(50);
        font.setBold(false);
        font.setWeight(50);
        name->setFont(font);
        name->setAutoFillBackground(false);
        name->setAlignment(Qt::AlignCenter);
        searchLineEditPermary = new QLineEdit(page);
        searchLineEditPermary->setObjectName(QStringLiteral("searchLineEditPermary"));
        searchLineEditPermary->setGeometry(QRect(150, 270, 581, 41));
        searchLineEditPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonPermary = new QPushButton(page);
        searchButtonPermary->setObjectName(QStringLiteral("searchButtonPermary"));
        searchButtonPermary->setGeometry(QRect(390, 410, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        searchButtonPermary->setFont(font1);
        searchButtonPermary->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonPermary->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        bookName_search = new QRadioButton(page);
        bookName_search->setObjectName(QStringLiteral("bookName_search"));
        bookName_search->setGeometry(QRect(150, 350, 89, 21));
        QFont font2;
        font2.setPointSize(14);
        bookName_search->setFont(font2);
        author_search = new QRadioButton(page);
        author_search->setObjectName(QStringLiteral("author_search"));
        author_search->setGeometry(QRect(320, 350, 89, 21));
        author_search->setFont(font2);
        isbn_search = new QRadioButton(page);
        isbn_search->setObjectName(QStringLiteral("isbn_search"));
        isbn_search->setGeometry(QRect(480, 350, 89, 21));
        isbn_search->setFont(font2);
        bookNumber_search = new QRadioButton(page);
        bookNumber_search->setObjectName(QStringLiteral("bookNumber_search"));
        bookNumber_search->setGeometry(QRect(630, 350, 111, 21));
        bookNumber_search->setFont(font2);
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
        searchLineEditBorrow->setGeometry(QRect(180, 20, 451, 31));
        QFont font3;
        font3.setPointSize(12);
        searchLineEditBorrow->setFont(font3);
        searchLineEditBorrow->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonBorrow = new QPushButton(mainWindowBackGroundFrame3);
        searchButtonBorrow->setObjectName(QStringLiteral("searchButtonBorrow"));
        searchButtonBorrow->setGeometry(QRect(670, 20, 71, 31));
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
        bookInformationborrow->setGeometry(QRect(30, 100, 801, 431));
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
        bookNameBorrow_search = new QRadioButton(mainWindowBackGroundFrame3);
        bookNameBorrow_search->setObjectName(QStringLiteral("bookNameBorrow_search"));
        bookNameBorrow_search->setGeometry(QRect(180, 70, 89, 16));
        bookNameBorrow_search->setFont(font3);
        authorBorrow_search = new QRadioButton(mainWindowBackGroundFrame3);
        authorBorrow_search->setObjectName(QStringLiteral("authorBorrow_search"));
        authorBorrow_search->setGeometry(QRect(300, 70, 89, 16));
        authorBorrow_search->setFont(font3);
        isbnBorrow_search = new QRadioButton(mainWindowBackGroundFrame3);
        isbnBorrow_search->setObjectName(QStringLiteral("isbnBorrow_search"));
        isbnBorrow_search->setGeometry(QRect(430, 70, 89, 16));
        isbnBorrow_search->setFont(font3);
        bookNumberBorrow_search = new QRadioButton(mainWindowBackGroundFrame3);
        bookNumberBorrow_search->setObjectName(QStringLiteral("bookNumberBorrow_search"));
        bookNumberBorrow_search->setGeometry(QRect(550, 70, 89, 16));
        bookNumberBorrow_search->setFont(font3);
        hasBeenBorrow = new QTableView(mainWindowBackGroundFrame3);
        hasBeenBorrow->setObjectName(QStringLiteral("hasBeenBorrow"));
        hasBeenBorrow->setGeometry(QRect(750, 50, 81, 51));
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
        mainWindowBackGroundFrame6->setStyleSheet(QStringLiteral("background:#fff"));
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
        mainWindowBackGroundFrame7->setStyleSheet(QStringLiteral("background:#fff"));
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
        payMoney = new QPushButton(mainWindowBackGroundFrame7);
        payMoney->setObjectName(QStringLiteral("payMoney"));
        payMoney->setGeometry(QRect(610, 490, 91, 31));
        payMoney->setFont(font4);
        payMoney->setCursor(QCursor(Qt::PointingHandCursor));
        payMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonMoney = new QPushButton(mainWindowBackGroundFrame7);
        returnButtonMoney->setObjectName(QStringLiteral("returnButtonMoney"));
        returnButtonMoney->setGeometry(QRect(20, 550, 91, 31));
        returnButtonMoney->setFont(font4);
        returnButtonMoney->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonMoney->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetPermary->addWidget(page_6);
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(940, 520, 91, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setWeight(50);
        quitButton->setFont(font5);
        quitButton->setCursor(QCursor(Qt::PointingHandCursor));
        quitButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        renewButton = new QPushButton(centralWidget);
        renewButton->setObjectName(QStringLiteral("renewButton"));
        renewButton->setGeometry(QRect(940, 230, 91, 31));
        renewButton->setFont(font5);
        renewButton->setCursor(QCursor(Qt::PointingHandCursor));
        renewButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        repayButton = new QPushButton(centralWidget);
        repayButton->setObjectName(QStringLiteral("repayButton"));
        repayButton->setGeometry(QRect(940, 150, 91, 31));
        repayButton->setFont(font5);
        repayButton->setCursor(QCursor(Qt::PointingHandCursor));
        repayButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowRecordButton = new QPushButton(centralWidget);
        borrowRecordButton->setObjectName(QStringLiteral("borrowRecordButton"));
        borrowRecordButton->setGeometry(QRect(940, 310, 91, 31));
        borrowRecordButton->setFont(font5);
        borrowRecordButton->setCursor(QCursor(Qt::PointingHandCursor));
        borrowRecordButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowButton = new QPushButton(centralWidget);
        borrowButton->setObjectName(QStringLiteral("borrowButton"));
        borrowButton->setGeometry(QRect(940, 70, 91, 31));
        borrowButton->setFont(font5);
        borrowButton->setCursor(QCursor(Qt::PointingHandCursor));
        borrowButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        moneyBotton = new QPushButton(centralWidget);
        moneyBotton->setObjectName(QStringLiteral("moneyBotton"));
        moneyBotton->setGeometry(QRect(940, 390, 91, 31));
        moneyBotton->setFont(font5);
        moneyBotton->setCursor(QCursor(Qt::PointingHandCursor));
        moneyBotton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(860, 0, 21, 641));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        stackedWidgetPermary->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        name->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        searchButtonPermary->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        bookName_search->setText(QApplication::translate("MainWindow", "\344\271\246\345\220\215", 0));
        author_search->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", 0));
        isbn_search->setText(QApplication::translate("MainWindow", "ISBN", 0));
        bookNumber_search->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\274\226\345\217\267", 0));
        searchLineEditBorrow->setText(QString());
        searchButtonBorrow->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        affirmBottonBorrow->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", 0));
        returnButtonBorrow->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0));
        bookNameBorrow_search->setText(QApplication::translate("MainWindow", "\344\271\246\345\220\215", 0));
        authorBorrow_search->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", 0));
        isbnBorrow_search->setText(QApplication::translate("MainWindow", "ISBN", 0));
        bookNumberBorrow_search->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\274\226\345\217\267", 0));
        affirmBottonRepay->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", 0));
        returnButtonRepay->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0));
        affirmBottonRenew->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", 0));
        returnButtonRenew->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0));
        returnBottonBorrowR->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0));
        passwordMoney->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        passwordMoneyInput->setText(QString());
        payMoney->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0));
        returnButtonMoney->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", 0));
        quitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        renewButton->setText(QApplication::translate("MainWindow", "\347\273\255\345\200\237", 0));
        repayButton->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", 0));
        borrowRecordButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246\350\256\260\345\275\225", 0));
        borrowButton->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", 0));
        moneyBotton->setText(QApplication::translate("MainWindow", "\347\274\264/\346\254\240\350\264\271", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
