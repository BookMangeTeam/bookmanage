/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
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
    QFrame *loginBackgroundFrame;
    QLabel *title;
    QLabel *user_name;
    QLineEdit *user_nameInput;
    QLabel *password;
    QLineEdit *passwordInput;
    QRadioButton *user_option;
    QRadioButton *administrator_option;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(429, 591);
        Login->setAutoFillBackground(false);
        Login->setStyleSheet(QStringLiteral(""));
        loginBackgroundFrame = new QFrame(Login);
        loginBackgroundFrame->setObjectName(QStringLiteral("loginBackgroundFrame"));
        loginBackgroundFrame->setGeometry(QRect(0, 0, 431, 591));
        loginBackgroundFrame->setAutoFillBackground(false);
        loginBackgroundFrame->setStyleSheet(QLatin1String("#loginBackgroundFrame{\n"
"border-image: url(:/1.jpg);\n"
"}"));
        loginBackgroundFrame->setFrameShape(QFrame::StyledPanel);
        loginBackgroundFrame->setFrameShadow(QFrame::Raised);
        title = new QLabel(loginBackgroundFrame);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(87, 100, 271, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(32);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAutoFillBackground(false);
        title->setStyleSheet(QStringLiteral(""));
        title->setAlignment(Qt::AlignCenter);
        user_name = new QLabel(loginBackgroundFrame);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setGeometry(QRect(180, 170, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        user_name->setFont(font1);
        user_name->setAlignment(Qt::AlignCenter);
        user_nameInput = new QLineEdit(loginBackgroundFrame);
        user_nameInput->setObjectName(QStringLiteral("user_nameInput"));
        user_nameInput->setGeometry(QRect(100, 220, 241, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        user_nameInput->setFont(font2);
        user_nameInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        user_nameInput->setEchoMode(QLineEdit::Normal);
        password = new QLabel(loginBackgroundFrame);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(190, 270, 61, 31));
        password->setFont(font1);
        password->setAlignment(Qt::AlignCenter);
        passwordInput = new QLineEdit(loginBackgroundFrame);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(100, 320, 241, 41));
        passwordInput->setFont(font2);
        passwordInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        passwordInput->setEchoMode(QLineEdit::Password);
        user_option = new QRadioButton(loginBackgroundFrame);
        user_option->setObjectName(QStringLiteral("user_option"));
        user_option->setGeometry(QRect(120, 380, 101, 21));
        user_option->setFont(font1);
        user_option->setLayoutDirection(Qt::LeftToRight);
        user_option->setChecked(true);
        administrator_option = new QRadioButton(loginBackgroundFrame);
        administrator_option->setObjectName(QStringLiteral("administrator_option"));
        administrator_option->setGeometry(QRect(250, 380, 91, 21));
        administrator_option->setFont(font1);
        loginButton = new QPushButton(loginBackgroundFrame);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(100, 430, 101, 41));
        loginButton->setFont(font1);
        loginButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        registerButton = new QPushButton(loginBackgroundFrame);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(240, 430, 101, 41));
        registerButton->setFont(font1);
        registerButton->setCursor(QCursor(Qt::PointingHandCursor));
        registerButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        title->setText(QApplication::translate("Login", "\345\233\276\344\271\246\351\246\206\347\263\273\347\273\237", 0));
        user_name->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0));
        password->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        user_option->setText(QApplication::translate("Login", "\347\224\250\346\210\267", 0));
        administrator_option->setText(QApplication::translate("Login", "\347\256\241\347\220\206\345\221\230", 0));
        loginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        registerButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
