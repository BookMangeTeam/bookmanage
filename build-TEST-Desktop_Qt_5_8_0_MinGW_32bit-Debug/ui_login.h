/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *user_nameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QRadioButton *user_option;
    QPushButton *registerButton;
    QLabel *user_name;
    QRadioButton *administrator_option;
    QLabel *password;
    QLabel *title;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(429, 645);
        Login->setStyleSheet(QStringLiteral("background-color:#fff"));
        user_nameInput = new QLineEdit(Login);
        user_nameInput->setObjectName(QStringLiteral("user_nameInput"));
        user_nameInput->setGeometry(QRect(90, 210, 241, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        user_nameInput->setFont(font);
        user_nameInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        user_nameInput->setEchoMode(QLineEdit::Normal);
        passwordInput = new QLineEdit(Login);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(90, 310, 241, 41));
        passwordInput->setFont(font);
        passwordInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        passwordInput->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(90, 490, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        loginButton->setFont(font1);
        loginButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        user_option = new QRadioButton(Login);
        user_option->setObjectName(QStringLiteral("user_option"));
        user_option->setGeometry(QRect(100, 380, 101, 21));
        user_option->setFont(font1);
        user_option->setLayoutDirection(Qt::LeftToRight);
        user_option->setChecked(true);
        registerButton = new QPushButton(Login);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(230, 490, 101, 41));
        registerButton->setFont(font1);
        registerButton->setCursor(QCursor(Qt::OpenHandCursor));
        registerButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        user_name = new QLabel(Login);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(170, 170, 81, 31));
        user_name->setFont(font1);
        user_name->setAlignment(Qt::AlignCenter);
        administrator_option = new QRadioButton(Login);
        administrator_option->setObjectName(QStringLiteral("administrator_option"));
        administrator_option->setGeometry(QRect(230, 380, 91, 21));
        administrator_option->setFont(font1);
        password = new QLabel(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(180, 270, 61, 31));
        password->setFont(font1);
        password->setAlignment(Qt::AlignCenter);
        title = new QLabel(Login);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(80, 50, 271, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(32);
        font2.setBold(false);
        font2.setWeight(50);
        title->setFont(font2);
        title->setAlignment(Qt::AlignCenter);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        user_option->setText(QApplication::translate("Login", "\347\224\250\346\210\267", Q_NULLPTR));
        registerButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
        user_name->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        administrator_option->setText(QApplication::translate("Login", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        password->setText(QApplication::translate("Login", "\345\257\206\347\240\201", Q_NULLPTR));
        title->setText(QApplication::translate("Login", "\345\233\276\344\271\246\351\246\206\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
