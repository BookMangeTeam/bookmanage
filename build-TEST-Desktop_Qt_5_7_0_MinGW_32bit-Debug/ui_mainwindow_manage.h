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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Manage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidgetManage;
    QWidget *page;
    QLabel *nameManage;
    QLineEdit *searchLineEditManage;
    QPushButton *searchButtonManage;
    QWidget *page_2;
    QPushButton *affirmBottonAdd;
    QPushButton *returnButtonAdd;
    QLineEdit *add_ISBN;
    QLabel *isbn;
    QLabel *bookName;
    QLineEdit *add_bookName;
    QLabel *author;
    QLineEdit *add_author;
    QLabel *publish;
    QLabel *price;
    QLineEdit *add_price;
    QLabel *amount;
    QLineEdit *add_amount;
    QLabel *status;
    QComboBox *add_status;
    QLabel *publishTime;
    QLineEdit *add_publish;
    QDateEdit *add_publishTime;
    QWidget *page_3;
    QTableView *bookInformationDelate;
    QPushButton *returnButtonDelate;
    QPushButton *affirmBottonDelate;
    QLineEdit *searchLineEditDelate;
    QPushButton *searchButtonDelate;
    QWidget *page_4;
    QTableView *bookInformationUpdate;
    QPushButton *returnButtonUpdate;
    QPushButton *affirmBottonUpdate;
    QLabel *updateOption;
    QComboBox *updateOption_CB;
    QLabel *updateTo;
    QLineEdit *updateTo_Input;
    QLineEdit *searchLineEditUpdate;
    QPushButton *searchButtonUpdate;
    QWidget *page_5;
    QTableView *bookInformationBRManage;
    QPushButton *returnBottonBRManage;
    QPushButton *deleteButton;
    QFrame *line;
    QPushButton *quitButtonManage;
    QPushButton *updateButton;
    QPushButton *borrowRecordButtonManage;
    QPushButton *addButton;
    QPushButton *btn_SignupManager;
    QPushButton *btn_manageSystem;

    void setupUi(QMainWindow *MainWindow_Manage)
    {
        if (MainWindow_Manage->objectName().isEmpty())
            MainWindow_Manage->setObjectName(QStringLiteral("MainWindow_Manage"));
        MainWindow_Manage->resize(1093, 651);
        MainWindow_Manage->setStyleSheet(QStringLiteral("background-color:#fff"));
        centralwidget = new QWidget(MainWindow_Manage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidgetManage = new QStackedWidget(centralwidget);
        stackedWidgetManage->setObjectName(QStringLiteral("stackedWidgetManage"));
        stackedWidgetManage->setGeometry(QRect(10, 20, 851, 611));
        stackedWidgetManage->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        nameManage = new QLabel(page);
        nameManage->setObjectName(QStringLiteral("nameManage"));
        nameManage->setGeometry(QRect(160, 60, 521, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(50);
        font.setBold(false);
        font.setWeight(50);
        nameManage->setFont(font);
        nameManage->setAlignment(Qt::AlignCenter);
        searchLineEditManage = new QLineEdit(page);
        searchLineEditManage->setObjectName(QStringLiteral("searchLineEditManage"));
        searchLineEditManage->setGeometry(QRect(150, 260, 541, 41));
        searchLineEditManage->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonManage = new QPushButton(page);
        searchButtonManage->setObjectName(QStringLiteral("searchButtonManage"));
        searchButtonManage->setGeometry(QRect(390, 330, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        searchButtonManage->setFont(font1);
        searchButtonManage->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonManage->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetManage->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        affirmBottonAdd = new QPushButton(page_2);
        affirmBottonAdd->setObjectName(QStringLiteral("affirmBottonAdd"));
        affirmBottonAdd->setGeometry(QRect(720, 520, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        affirmBottonAdd->setFont(font2);
        affirmBottonAdd->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonAdd->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        returnButtonAdd = new QPushButton(page_2);
        returnButtonAdd->setObjectName(QStringLiteral("returnButtonAdd"));
        returnButtonAdd->setGeometry(QRect(50, 520, 91, 31));
        returnButtonAdd->setFont(font2);
        returnButtonAdd->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonAdd->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        add_ISBN = new QLineEdit(page_2);
        add_ISBN->setObjectName(QStringLiteral("add_ISBN"));
        add_ISBN->setGeometry(QRect(370, 10, 271, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        add_ISBN->setFont(font3);
        add_ISBN->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        isbn = new QLabel(page_2);
        isbn->setObjectName(QStringLiteral("isbn"));
        isbn->setGeometry(QRect(210, 10, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(14);
        isbn->setFont(font4);
        isbn->setStyleSheet(QStringLiteral(""));
        isbn->setAlignment(Qt::AlignCenter);
        bookName = new QLabel(page_2);
        bookName->setObjectName(QStringLiteral("bookName"));
        bookName->setGeometry(QRect(220, 70, 71, 31));
        bookName->setFont(font4);
        bookName->setAlignment(Qt::AlignCenter);
        add_bookName = new QLineEdit(page_2);
        add_bookName->setObjectName(QStringLiteral("add_bookName"));
        add_bookName->setGeometry(QRect(370, 70, 271, 31));
        add_bookName->setFont(font3);
        add_bookName->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        author = new QLabel(page_2);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(220, 130, 71, 31));
        author->setFont(font4);
        author->setAlignment(Qt::AlignCenter);
        add_author = new QLineEdit(page_2);
        add_author->setObjectName(QStringLiteral("add_author"));
        add_author->setGeometry(QRect(370, 130, 271, 31));
        add_author->setFont(font3);
        add_author->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        publish = new QLabel(page_2);
        publish->setObjectName(QStringLiteral("publish"));
        publish->setGeometry(QRect(220, 190, 81, 31));
        publish->setFont(font4);
        publish->setAlignment(Qt::AlignCenter);
        price = new QLabel(page_2);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(230, 310, 61, 31));
        price->setFont(font4);
        price->setAlignment(Qt::AlignCenter);
        add_price = new QLineEdit(page_2);
        add_price->setObjectName(QStringLiteral("add_price"));
        add_price->setGeometry(QRect(370, 310, 271, 31));
        add_price->setFont(font3);
        add_price->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        amount = new QLabel(page_2);
        amount->setObjectName(QStringLiteral("amount"));
        amount->setGeometry(QRect(230, 370, 61, 31));
        amount->setFont(font4);
        amount->setAlignment(Qt::AlignCenter);
        add_amount = new QLineEdit(page_2);
        add_amount->setObjectName(QStringLiteral("add_amount"));
        add_amount->setGeometry(QRect(370, 370, 271, 31));
        add_amount->setFont(font3);
        add_amount->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        status = new QLabel(page_2);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(230, 430, 61, 31));
        status->setFont(font4);
        status->setAlignment(Qt::AlignCenter);
        add_status = new QComboBox(page_2);
        add_status->setObjectName(QStringLiteral("add_status"));
        add_status->setGeometry(QRect(370, 430, 271, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font5.setPointSize(12);
        add_status->setFont(font5);
        add_status->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;text-align:center"));
        publishTime = new QLabel(page_2);
        publishTime->setObjectName(QStringLiteral("publishTime"));
        publishTime->setGeometry(QRect(210, 250, 101, 31));
        publishTime->setFont(font4);
        publishTime->setAlignment(Qt::AlignCenter);
        add_publish = new QLineEdit(page_2);
        add_publish->setObjectName(QStringLiteral("add_publish"));
        add_publish->setGeometry(QRect(370, 190, 271, 31));
        add_publish->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        add_publishTime = new QDateEdit(page_2);
        add_publishTime->setObjectName(QStringLiteral("add_publishTime"));
        add_publishTime->setGeometry(QRect(370, 250, 271, 31));
        add_publishTime->setFont(font5);
        add_publishTime->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        add_publishTime->setAlignment(Qt::AlignCenter);
        stackedWidgetManage->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        bookInformationDelate = new QTableView(page_3);
        bookInformationDelate->setObjectName(QStringLiteral("bookInformationDelate"));
        bookInformationDelate->setGeometry(QRect(10, 90, 821, 411));
        bookInformationDelate->setStyleSheet(QStringLiteral(""));
        returnButtonDelate = new QPushButton(page_3);
        returnButtonDelate->setObjectName(QStringLiteral("returnButtonDelate"));
        returnButtonDelate->setGeometry(QRect(50, 520, 91, 31));
        returnButtonDelate->setFont(font2);
        returnButtonDelate->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonDelate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        affirmBottonDelate = new QPushButton(page_3);
        affirmBottonDelate->setObjectName(QStringLiteral("affirmBottonDelate"));
        affirmBottonDelate->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonDelate->setFont(font2);
        affirmBottonDelate->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonDelate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        searchLineEditDelate = new QLineEdit(page_3);
        searchLineEditDelate->setObjectName(QStringLiteral("searchLineEditDelate"));
        searchLineEditDelate->setGeometry(QRect(170, 30, 451, 31));
        searchLineEditDelate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonDelate = new QPushButton(page_3);
        searchButtonDelate->setObjectName(QStringLiteral("searchButtonDelate"));
        searchButtonDelate->setGeometry(QRect(680, 30, 71, 31));
        searchButtonDelate->setFont(font4);
        searchButtonDelate->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonDelate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetManage->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        bookInformationUpdate = new QTableView(page_4);
        bookInformationUpdate->setObjectName(QStringLiteral("bookInformationUpdate"));
        bookInformationUpdate->setGeometry(QRect(0, 90, 841, 251));
        bookInformationUpdate->setStyleSheet(QStringLiteral(""));
        returnButtonUpdate = new QPushButton(page_4);
        returnButtonUpdate->setObjectName(QStringLiteral("returnButtonUpdate"));
        returnButtonUpdate->setGeometry(QRect(50, 520, 91, 31));
        returnButtonUpdate->setFont(font2);
        returnButtonUpdate->setCursor(QCursor(Qt::PointingHandCursor));
        returnButtonUpdate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        affirmBottonUpdate = new QPushButton(page_4);
        affirmBottonUpdate->setObjectName(QStringLiteral("affirmBottonUpdate"));
        affirmBottonUpdate->setGeometry(QRect(720, 520, 91, 31));
        affirmBottonUpdate->setFont(font2);
        affirmBottonUpdate->setCursor(QCursor(Qt::PointingHandCursor));
        affirmBottonUpdate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        updateOption = new QLabel(page_4);
        updateOption->setObjectName(QStringLiteral("updateOption"));
        updateOption->setGeometry(QRect(180, 376, 142, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font6.setPointSize(15);
        updateOption->setFont(font6);
        updateOption->setAlignment(Qt::AlignCenter);
        updateOption_CB = new QComboBox(page_4);
        updateOption_CB->setObjectName(QStringLiteral("updateOption_CB"));
        updateOption_CB->setGeometry(QRect(370, 370, 161, 31));
        QFont font7;
        font7.setPointSize(12);
        updateOption_CB->setFont(font7);
        updateOption_CB->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        updateTo = new QLabel(page_4);
        updateTo->setObjectName(QStringLiteral("updateTo"));
        updateTo->setGeometry(QRect(220, 435, 71, 21));
        updateTo->setFont(font6);
        updateTo->setAlignment(Qt::AlignCenter);
        updateTo_Input = new QLineEdit(page_4);
        updateTo_Input->setObjectName(QStringLiteral("updateTo_Input"));
        updateTo_Input->setGeometry(QRect(370, 430, 291, 31));
        updateTo_Input->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchLineEditUpdate = new QLineEdit(page_4);
        searchLineEditUpdate->setObjectName(QStringLiteral("searchLineEditUpdate"));
        searchLineEditUpdate->setGeometry(QRect(170, 30, 451, 31));
        searchLineEditUpdate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        searchButtonUpdate = new QPushButton(page_4);
        searchButtonUpdate->setObjectName(QStringLiteral("searchButtonUpdate"));
        searchButtonUpdate->setGeometry(QRect(680, 30, 71, 31));
        searchButtonUpdate->setFont(font2);
        searchButtonUpdate->setCursor(QCursor(Qt::PointingHandCursor));
        searchButtonUpdate->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetManage->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        bookInformationBRManage = new QTableView(page_5);
        bookInformationBRManage->setObjectName(QStringLiteral("bookInformationBRManage"));
        bookInformationBRManage->setGeometry(QRect(10, 40, 811, 461));
        bookInformationBRManage->setStyleSheet(QStringLiteral(""));
        returnBottonBRManage = new QPushButton(page_5);
        returnBottonBRManage->setObjectName(QStringLiteral("returnBottonBRManage"));
        returnBottonBRManage->setGeometry(QRect(50, 520, 91, 31));
        returnBottonBRManage->setFont(font2);
        returnBottonBRManage->setCursor(QCursor(Qt::PointingHandCursor));
        returnBottonBRManage->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        stackedWidgetManage->addWidget(page_5);
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(940, 150, 91, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        deleteButton->setFont(font8);
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(860, 10, 20, 591));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        quitButtonManage = new QPushButton(centralwidget);
        quitButtonManage->setObjectName(QStringLiteral("quitButtonManage"));
        quitButtonManage->setGeometry(QRect(940, 540, 91, 31));
        quitButtonManage->setFont(font8);
        quitButtonManage->setCursor(QCursor(Qt::PointingHandCursor));
        quitButtonManage->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(940, 230, 91, 31));
        updateButton->setFont(font8);
        updateButton->setCursor(QCursor(Qt::PointingHandCursor));
        updateButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        borrowRecordButtonManage = new QPushButton(centralwidget);
        borrowRecordButtonManage->setObjectName(QStringLiteral("borrowRecordButtonManage"));
        borrowRecordButtonManage->setGeometry(QRect(940, 310, 91, 31));
        borrowRecordButtonManage->setFont(font8);
        borrowRecordButtonManage->setCursor(QCursor(Qt::PointingHandCursor));
        borrowRecordButtonManage->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(940, 70, 91, 31));
        addButton->setFont(font8);
        addButton->setCursor(QCursor(Qt::PointingHandCursor));
        addButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        btn_SignupManager = new QPushButton(centralwidget);
        btn_SignupManager->setObjectName(QStringLiteral("btn_SignupManager"));
        btn_SignupManager->setGeometry(QRect(940, 470, 93, 31));
        btn_SignupManager->setFont(font5);
        btn_SignupManager->setCursor(QCursor(Qt::PointingHandCursor));
        btn_SignupManager->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        btn_manageSystem = new QPushButton(centralwidget);
        btn_manageSystem->setObjectName(QStringLiteral("btn_manageSystem"));
        btn_manageSystem->setGeometry(QRect(940, 390, 93, 31));
        btn_manageSystem->setFont(font5);
        btn_manageSystem->setCursor(QCursor(Qt::PointingHandCursor));
        btn_manageSystem->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        MainWindow_Manage->setCentralWidget(centralwidget);

        retranslateUi(MainWindow_Manage);

        stackedWidgetManage->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow_Manage);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Manage)
    {
        MainWindow_Manage->setWindowTitle(QApplication::translate("MainWindow_Manage", "MainWindow", 0));
        nameManage->setText(QApplication::translate("MainWindow_Manage", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        searchButtonManage->setText(QApplication::translate("MainWindow_Manage", "\346\220\234\347\264\242", 0));
        affirmBottonAdd->setText(QApplication::translate("MainWindow_Manage", "\345\242\236\345\212\240", 0));
        returnButtonAdd->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        isbn->setText(QApplication::translate("MainWindow_Manage", "ISBN\347\240\201", 0));
        bookName->setText(QApplication::translate("MainWindow_Manage", "\344\271\246\345\220\215", 0));
        author->setText(QApplication::translate("MainWindow_Manage", "\344\275\234\350\200\205", 0));
        publish->setText(QApplication::translate("MainWindow_Manage", "\345\207\272\347\211\210\347\244\276", 0));
        price->setText(QApplication::translate("MainWindow_Manage", "\344\273\267\346\240\274", 0));
        amount->setText(QApplication::translate("MainWindow_Manage", "\346\225\260\351\207\217", 0));
        status->setText(QApplication::translate("MainWindow_Manage", "\347\212\266\346\200\201", 0));
        add_status->clear();
        add_status->insertItems(0, QStringList()
         << QApplication::translate("MainWindow_Manage", "    \345\217\257\345\200\237\351\230\205", 0)
         << QApplication::translate("MainWindow_Manage", "   \344\270\215\345\217\257\345\200\237\351\230\205", 0)
        );
        publishTime->setText(QApplication::translate("MainWindow_Manage", "\345\207\272\347\211\210\346\227\266\351\227\264", 0));
        returnButtonDelate->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        affirmBottonDelate->setText(QApplication::translate("MainWindow_Manage", "\345\210\240\351\231\244", 0));
        searchButtonDelate->setText(QApplication::translate("MainWindow_Manage", "\346\220\234\347\264\242", 0));
        returnButtonUpdate->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        affirmBottonUpdate->setText(QApplication::translate("MainWindow_Manage", "\346\233\264\346\224\271", 0));
        updateOption->setText(QApplication::translate("MainWindow_Manage", "\351\241\271\347\233\256", 0));
        updateOption_CB->clear();
        updateOption_CB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow_Manage", "       ISBN", 0)
         << QApplication::translate("MainWindow_Manage", "       \344\271\246\345\220\215", 0)
         << QApplication::translate("MainWindow_Manage", "       \344\275\234\350\200\205", 0)
         << QApplication::translate("MainWindow_Manage", "     \345\207\272\347\211\210\347\244\276", 0)
         << QApplication::translate("MainWindow_Manage", "    \345\207\272\347\211\210\346\227\266\351\227\264", 0)
         << QApplication::translate("MainWindow_Manage", "       \344\273\267\346\240\274", 0)
         << QApplication::translate("MainWindow_Manage", "       \347\212\266\346\200\201", 0)
        );
        updateTo->setText(QApplication::translate("MainWindow_Manage", "\346\233\264\346\224\271\344\270\272", 0));
        searchButtonUpdate->setText(QApplication::translate("MainWindow_Manage", "\346\220\234\347\264\242", 0));
        returnBottonBRManage->setText(QApplication::translate("MainWindow_Manage", "\350\277\224\345\233\236", 0));
        deleteButton->setText(QApplication::translate("MainWindow_Manage", "\345\210\240\351\231\244\345\233\276\344\271\246", 0));
        quitButtonManage->setText(QApplication::translate("MainWindow_Manage", "\351\200\200\345\207\272", 0));
        updateButton->setText(QApplication::translate("MainWindow_Manage", "\346\233\264\346\224\271\344\277\241\346\201\257", 0));
        borrowRecordButtonManage->setText(QApplication::translate("MainWindow_Manage", "\345\200\237\351\230\205\350\256\260\345\275\225", 0));
        addButton->setText(QApplication::translate("MainWindow_Manage", "\345\242\236\345\212\240\345\233\276\344\271\246", 0));
        btn_SignupManager->setText(QApplication::translate("MainWindow_Manage", "\346\263\250\345\206\214", 0));
        btn_manageSystem->setText(QApplication::translate("MainWindow_Manage", "\347\263\273\347\273\237\346\223\215\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Manage: public Ui_MainWindow_Manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MANAGE_H
