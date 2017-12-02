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
#include <QtWidgets/QFrame>
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
    QFrame *registerBackgroundFrame;
    QLabel *register_2;
    QLabel *register_userName;
    QLineEdit *register_userNameinput;
    QLabel *register_password;
    QLineEdit *register_passwordInput;
    QLabel *register_passwordAffirm;
    QLineEdit *register_passwordAffirmInput;
    QLabel *academy;
    QComboBox *academyInput;
    QLabel *label;
    QRadioButton *user_optionRegister;
    QRadioButton *administrator_optionRegister;
    QPushButton *affirmReisterButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(446, 710);
        Register->setStyleSheet(QStringLiteral(""));
        registerBackgroundFrame = new QFrame(Register);
        registerBackgroundFrame->setObjectName(QStringLiteral("registerBackgroundFrame"));
        registerBackgroundFrame->setGeometry(QRect(0, 0, 445, 711));
        registerBackgroundFrame->setStyleSheet(QLatin1String("#registerBackgroundFrame{\n"
"background-image: url(:/2.jpg);\n"
"}"));
        registerBackgroundFrame->setFrameShape(QFrame::StyledPanel);
        registerBackgroundFrame->setFrameShadow(QFrame::Raised);
        register_2 = new QLabel(registerBackgroundFrame);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(125, 20, 211, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        register_2->setFont(font);
        register_2->setAlignment(Qt::AlignCenter);
        register_userName = new QLabel(registerBackgroundFrame);
        register_userName->setObjectName(QStringLiteral("register_userName"));
        register_userName->setGeometry(QRect(179, 100, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        register_userName->setFont(font1);
        register_userName->setAlignment(Qt::AlignCenter);
        register_userNameinput = new QLineEdit(registerBackgroundFrame);
        register_userNameinput->setObjectName(QStringLiteral("register_userNameinput"));
        register_userNameinput->setGeometry(QRect(102, 140, 241, 41));
        QFont font2;
        font2.setPointSize(12);
        register_userNameinput->setFont(font2);
        register_userNameinput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_password = new QLabel(registerBackgroundFrame);
        register_password->setObjectName(QStringLiteral("register_password"));
        register_password->setGeometry(QRect(189, 200, 61, 31));
        register_password->setFont(font1);
        register_password->setAlignment(Qt::AlignCenter);
        register_passwordInput = new QLineEdit(registerBackgroundFrame);
        register_passwordInput->setObjectName(QStringLiteral("register_passwordInput"));
        register_passwordInput->setGeometry(QRect(101, 240, 241, 41));
        register_passwordInput->setFont(font2);
        register_passwordInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordInput->setEchoMode(QLineEdit::Password);
        register_passwordAffirm = new QLabel(registerBackgroundFrame);
        register_passwordAffirm->setObjectName(QStringLiteral("register_passwordAffirm"));
        register_passwordAffirm->setGeometry(QRect(182, 300, 101, 20));
        register_passwordAffirm->setFont(font1);
        register_passwordAffirmInput = new QLineEdit(registerBackgroundFrame);
        register_passwordAffirmInput->setObjectName(QStringLiteral("register_passwordAffirmInput"));
        register_passwordAffirmInput->setGeometry(QRect(100, 340, 241, 41));
        register_passwordAffirmInput->setFont(font2);
        register_passwordAffirmInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordAffirmInput->setEchoMode(QLineEdit::Password);
        academy = new QLabel(registerBackgroundFrame);
        academy->setObjectName(QStringLiteral("academy"));
        academy->setGeometry(QRect(172, 391, 101, 31));
        academy->setFont(font1);
        academy->setAlignment(Qt::AlignCenter);
        academyInput = new QComboBox(registerBackgroundFrame);
        academyInput->setObjectName(QStringLiteral("academyInput"));
        academyInput->setGeometry(QRect(100, 430, 241, 41));
        academyInput->setFont(font1);
        academyInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        label = new QLabel(registerBackgroundFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 490, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(14);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        user_optionRegister = new QRadioButton(registerBackgroundFrame);
        user_optionRegister->setObjectName(QStringLiteral("user_optionRegister"));
        user_optionRegister->setGeometry(QRect(125, 550, 89, 21));
        user_optionRegister->setFont(font3);
        user_optionRegister->setChecked(false);
        administrator_optionRegister = new QRadioButton(registerBackgroundFrame);
        administrator_optionRegister->setObjectName(QStringLiteral("administrator_optionRegister"));
        administrator_optionRegister->setGeometry(QRect(258, 550, 89, 21));
        administrator_optionRegister->setFont(font3);
        affirmReisterButton = new QPushButton(registerBackgroundFrame);
        affirmReisterButton->setObjectName(QStringLiteral("affirmReisterButton"));
        affirmReisterButton->setGeometry(QRect(161, 620, 112, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(17);
        font4.setBold(true);
        font4.setWeight(75);
        affirmReisterButton->setFont(font4);
        affirmReisterButton->setCursor(QCursor(Qt::PointingHandCursor));
        affirmReisterButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        register_2->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        register_userName->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
#ifndef QT_NO_TOOLTIP
        register_userNameinput->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        register_password->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        register_passwordAffirm->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        academy->setText(QApplication::translate("Register", "\346\211\200\345\234\250\345\255\246\351\231\242", 0));
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
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\347\261\273\345\236\213", 0));
        user_optionRegister->setText(QApplication::translate("Register", "\347\224\250\346\210\267", 0));
        administrator_optionRegister->setText(QApplication::translate("Register", "\347\256\241\347\220\206\345\221\230", 0));
        affirmReisterButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
