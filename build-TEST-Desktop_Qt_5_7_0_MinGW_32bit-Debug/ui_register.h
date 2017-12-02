/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *register_passwordAffirm;
    QLineEdit *register_passwordAffirmInput;
    QLabel *register_userName;
    QLabel *academy;
    QLineEdit *register_userNameinput;
    QLineEdit *register_passwordInput;
    QLabel *register_2;
    QLabel *register_password;
    QPushButton *affirmReisterButton;
    QComboBox *academyInput;
    QRadioButton *user_optionRegister;
    QLabel *label;
    QRadioButton *administrator_optionRegister;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(446, 710);
        Register->setStyleSheet(QStringLiteral("background-color:#fff"));
        register_passwordAffirm = new QLabel(Register);
        register_passwordAffirm->setObjectName(QStringLiteral("register_passwordAffirm"));
        register_passwordAffirm->setGeometry(QRect(180, 320, 101, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        register_passwordAffirm->setFont(font);
        register_passwordAffirmInput = new QLineEdit(Register);
        register_passwordAffirmInput->setObjectName(QStringLiteral("register_passwordAffirmInput"));
        register_passwordAffirmInput->setGeometry(QRect(100, 350, 241, 41));
        QFont font1;
        font1.setPointSize(12);
        register_passwordAffirmInput->setFont(font1);
        register_passwordAffirmInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordAffirmInput->setEchoMode(QLineEdit::Password);
        register_userName = new QLabel(Register);
        register_userName->setObjectName(QStringLiteral("register_userName"));
        register_userName->setGeometry(QRect(180, 110, 81, 31));
        register_userName->setFont(font);
        register_userName->setAlignment(Qt::AlignCenter);
        academy = new QLabel(Register);
        academy->setObjectName(QStringLiteral("academy"));
        academy->setGeometry(QRect(170, 420, 101, 31));
        academy->setFont(font);
        academy->setAlignment(Qt::AlignCenter);
        register_userNameinput = new QLineEdit(Register);
        register_userNameinput->setObjectName(QStringLiteral("register_userNameinput"));
        register_userNameinput->setGeometry(QRect(100, 150, 241, 41));
        register_userNameinput->setFont(font1);
        register_userNameinput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordInput = new QLineEdit(Register);
        register_passwordInput->setObjectName(QStringLiteral("register_passwordInput"));
        register_passwordInput->setGeometry(QRect(100, 250, 241, 41));
        register_passwordInput->setFont(font1);
        register_passwordInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordInput->setEchoMode(QLineEdit::Password);
        register_2 = new QLabel(Register);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(120, 20, 211, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(36);
        font2.setBold(false);
        font2.setWeight(50);
        register_2->setFont(font2);
        register_2->setAlignment(Qt::AlignCenter);
        register_password = new QLabel(Register);
        register_password->setObjectName(QStringLiteral("register_password"));
        register_password->setGeometry(QRect(190, 211, 61, 31));
        register_password->setFont(font);
        register_password->setAlignment(Qt::AlignCenter);
        affirmReisterButton = new QPushButton(Register);
        affirmReisterButton->setObjectName(QStringLiteral("affirmReisterButton"));
        affirmReisterButton->setGeometry(QRect(170, 640, 112, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setWeight(75);
        affirmReisterButton->setFont(font3);
        affirmReisterButton->setCursor(QCursor(Qt::PointingHandCursor));
        affirmReisterButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        academyInput = new QComboBox(Register);
        academyInput->setObjectName(QStringLiteral("academyInput"));
        academyInput->setGeometry(QRect(100, 460, 241, 41));
        academyInput->setFont(font);
        academyInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        user_optionRegister = new QRadioButton(Register);
        user_optionRegister->setObjectName(QStringLiteral("user_optionRegister"));
        user_optionRegister->setGeometry(QRect(110, 580, 89, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(14);
        user_optionRegister->setFont(font4);
        user_optionRegister->setChecked(false);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 530, 101, 31));
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        administrator_optionRegister = new QRadioButton(Register);
        administrator_optionRegister->setObjectName(QStringLiteral("administrator_optionRegister"));
        administrator_optionRegister->setGeometry(QRect(260, 580, 89, 21));
        administrator_optionRegister->setFont(font4);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        register_passwordAffirm->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        register_userName->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
        academy->setText(QApplication::translate("Register", "\346\211\200\345\234\250\345\255\246\351\231\242", 0));
#ifndef QT_NO_TOOLTIP
        register_userNameinput->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        register_2->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        register_password->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        affirmReisterButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244\346\263\250\345\206\214", 0));
        academyInput->clear();
        academyInput->insertItems(0, QStringList()
         << QApplication::translate("Register", "\344\277\241\346\201\257\347\247\221\345\255\246\344\270\216\345\267\245\347\250\213\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\346\265\267\346\264\213\344\270\216\345\244\247\346\260\224\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\346\260\264\344\272\247\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\347\256\241\347\220\206\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\347\273\217\346\265\216\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\346\263\225\346\224\277\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242", 0)
         << QApplication::translate("Register", "\345\214\226\345\255\246\345\214\226\345\267\245\345\255\246\351\231\242", 0)
        );
        user_optionRegister->setText(QApplication::translate("Register", "\347\224\250\346\210\267", 0));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\347\261\273\345\236\213", 0));
        administrator_optionRegister->setText(QApplication::translate("Register", "\347\256\241\347\220\206\345\221\230", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
