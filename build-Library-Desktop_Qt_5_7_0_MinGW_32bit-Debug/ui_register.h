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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *register_2;
    QLabel *register_userName;
    QLineEdit *register_userNameinput;
    QLabel *register_password;
    QLineEdit *register_passwordInput;
    QLineEdit *register_passwordAffirmInput;
    QLabel *register_passwordAffirm;
    QComboBox *academyInput;
    QLabel *academy;
    QRadioButton *user_optionRegister;
    QRadioButton *administrator_optionRegister;
    QLabel *iAm;
    QPushButton *affirmReisterButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(470, 694);
        QFont font;
        font.setPointSize(12);
        Register->setFont(font);
        register_2 = new QLabel(Register);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(10, 10, 451, 61));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        register_2->setFont(font1);
        register_2->setAlignment(Qt::AlignCenter);
        register_userName = new QLabel(Register);
        register_userName->setObjectName(QStringLiteral("register_userName"));
        register_userName->setGeometry(QRect(40, 110, 61, 31));
        QFont font2;
        font2.setPointSize(14);
        register_userName->setFont(font2);
        register_userName->setAlignment(Qt::AlignCenter);
        register_userNameinput = new QLineEdit(Register);
        register_userNameinput->setObjectName(QStringLiteral("register_userNameinput"));
        register_userNameinput->setGeometry(QRect(120, 110, 191, 31));
        register_userNameinput->setFont(font);
        register_password = new QLabel(Register);
        register_password->setObjectName(QStringLiteral("register_password"));
        register_password->setGeometry(QRect(40, 201, 61, 31));
        register_password->setFont(font2);
        register_password->setAlignment(Qt::AlignCenter);
        register_passwordInput = new QLineEdit(Register);
        register_passwordInput->setObjectName(QStringLiteral("register_passwordInput"));
        register_passwordInput->setGeometry(QRect(120, 199, 191, 31));
        register_passwordInput->setFont(font);
        register_passwordInput->setEchoMode(QLineEdit::Password);
        register_passwordAffirmInput = new QLineEdit(Register);
        register_passwordAffirmInput->setObjectName(QStringLiteral("register_passwordAffirmInput"));
        register_passwordAffirmInput->setGeometry(QRect(120, 290, 191, 31));
        register_passwordAffirmInput->setFont(font);
        register_passwordAffirmInput->setEchoMode(QLineEdit::Password);
        register_passwordAffirm = new QLabel(Register);
        register_passwordAffirm->setObjectName(QStringLiteral("register_passwordAffirm"));
        register_passwordAffirm->setGeometry(QRect(30, 297, 81, 20));
        register_passwordAffirm->setFont(font2);
        academyInput = new QComboBox(Register);
        academyInput->setObjectName(QStringLiteral("academyInput"));
        academyInput->setGeometry(QRect(120, 380, 191, 31));
        academyInput->setFont(font);
        academy = new QLabel(Register);
        academy->setObjectName(QStringLiteral("academy"));
        academy->setGeometry(QRect(30, 386, 81, 20));
        academy->setFont(font2);
        academy->setAlignment(Qt::AlignCenter);
        user_optionRegister = new QRadioButton(Register);
        user_optionRegister->setObjectName(QStringLiteral("user_optionRegister"));
        user_optionRegister->setGeometry(QRect(120, 470, 89, 16));
        user_optionRegister->setFont(font);
        user_optionRegister->setChecked(true);
        administrator_optionRegister = new QRadioButton(Register);
        administrator_optionRegister->setObjectName(QStringLiteral("administrator_optionRegister"));
        administrator_optionRegister->setGeometry(QRect(240, 470, 89, 16));
        iAm = new QLabel(Register);
        iAm->setObjectName(QStringLiteral("iAm"));
        iAm->setGeometry(QRect(39, 467, 61, 21));
        iAm->setFont(font2);
        iAm->setAlignment(Qt::AlignCenter);
        affirmReisterButton = new QPushButton(Register);
        affirmReisterButton->setObjectName(QStringLiteral("affirmReisterButton"));
        affirmReisterButton->setGeometry(QRect(170, 580, 131, 51));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        affirmReisterButton->setFont(font3);
        affirmReisterButton->setCursor(QCursor(Qt::OpenHandCursor));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", 0));
        register_2->setText(QApplication::translate("Register", "\346\254\242\350\277\216\346\263\250\345\206\214", 0));
        register_userName->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
#ifndef QT_NO_TOOLTIP
        register_userNameinput->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        register_password->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        register_passwordAffirm->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
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
        academy->setText(QApplication::translate("Register", "\346\211\200\345\234\250\345\255\246\351\231\242", 0));
        user_optionRegister->setText(QApplication::translate("Register", "\347\224\250\346\210\267", 0));
        administrator_optionRegister->setText(QApplication::translate("Register", "\347\256\241\347\220\206\345\221\230", 0));
        iAm->setText(QApplication::translate("Register", "\346\210\221\346\230\257", 0));
        affirmReisterButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
