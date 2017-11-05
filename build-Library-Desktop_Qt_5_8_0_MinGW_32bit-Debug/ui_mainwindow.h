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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *title;
    QLabel *user_name;
    QLineEdit *user_nameInput;
    QLabel *password;
    QLineEdit *passwordInput;
    QRadioButton *user_option;
    QRadioButton *administrator_option;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(396, 460);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(396, 460));
        MainWindow->setMaximumSize(QSize(396, 460));
        MainWindow->setBaseSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(10, 5, 381, 61));
        QFont font;
        font.setPointSize(38);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        user_name = new QLabel(centralWidget);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(40, 120, 81, 31));
        QFont font1;
        font1.setPointSize(20);
        user_name->setFont(font1);
        user_name->setAlignment(Qt::AlignCenter);
        user_nameInput = new QLineEdit(centralWidget);
        user_nameInput->setObjectName(QStringLiteral("user_nameInput"));
        user_nameInput->setGeometry(QRect(150, 120, 191, 31));
        QFont font2;
        font2.setPointSize(12);
        user_nameInput->setFont(font2);
        user_nameInput->setEchoMode(QLineEdit::Normal);
        password = new QLabel(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(50, 180, 61, 31));
        password->setFont(font1);
        password->setAlignment(Qt::AlignCenter);
        passwordInput = new QLineEdit(centralWidget);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(150, 180, 191, 31));
        passwordInput->setFont(font2);
        passwordInput->setEchoMode(QLineEdit::Password);
        user_option = new QRadioButton(centralWidget);
        user_option->setObjectName(QStringLiteral("user_option"));
        user_option->setGeometry(QRect(70, 250, 101, 21));
        QFont font3;
        font3.setPointSize(14);
        user_option->setFont(font3);
        user_option->setLayoutDirection(Qt::LeftToRight);
        user_option->setChecked(true);
        administrator_option = new QRadioButton(centralWidget);
        administrator_option->setObjectName(QStringLiteral("administrator_option"));
        administrator_option->setGeometry(QRect(220, 250, 91, 21));
        administrator_option->setFont(font3);
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(60, 340, 81, 31));
        loginButton->setFont(font1);
        loginButton->setCursor(QCursor(Qt::OpenHandCursor));
        registerButton = new QPushButton(centralWidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(220, 340, 81, 31));
        registerButton->setFont(font1);
        registerButton->setCursor(QCursor(Qt::OpenHandCursor));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        title->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206\347\263\273\347\273\237", Q_NULLPTR));
        user_name->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        password->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        user_option->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267", Q_NULLPTR));
        administrator_option->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        loginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        registerButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
