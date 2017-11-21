/********************************************************************************
** Form generated from reading UI file 'registermanager.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERMANAGER_H
#define UI_REGISTERMANAGER_H

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

class Ui_RegisterManager
{
public:
    QLabel *register_2;
    QLineEdit *register_passwordInput;
    QLineEdit *register_passwordAffirmInput;
    QLabel *register_password;
    QLabel *register_passwordAffirm;
    QRadioButton *user_optionRegister;
    QLabel *academy;
    QLineEdit *register_userNameinput;
    QPushButton *affirmReisterButton;
    QLabel *register_userName;
    QLabel *iAm;
    QComboBox *academyInput;
    QRadioButton *administrator_optionRegister;

    void setupUi(QWidget *RegisterManager)
    {
        if (RegisterManager->objectName().isEmpty())
            RegisterManager->setObjectName(QStringLiteral("RegisterManager"));
        RegisterManager->resize(420, 710);
        register_2 = new QLabel(RegisterManager);
        register_2->setObjectName(QStringLiteral("register_2"));
        register_2->setGeometry(QRect(120, 10, 211, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        register_2->setFont(font);
        register_2->setAlignment(Qt::AlignCenter);
        register_passwordInput = new QLineEdit(RegisterManager);
        register_passwordInput->setObjectName(QStringLiteral("register_passwordInput"));
        register_passwordInput->setGeometry(QRect(100, 240, 241, 41));
        QFont font1;
        font1.setPointSize(12);
        register_passwordInput->setFont(font1);
        register_passwordInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordInput->setEchoMode(QLineEdit::Password);
        register_passwordAffirmInput = new QLineEdit(RegisterManager);
        register_passwordAffirmInput->setObjectName(QStringLiteral("register_passwordAffirmInput"));
        register_passwordAffirmInput->setGeometry(QRect(100, 340, 241, 41));
        register_passwordAffirmInput->setFont(font1);
        register_passwordAffirmInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        register_passwordAffirmInput->setEchoMode(QLineEdit::Password);
        register_password = new QLabel(RegisterManager);
        register_password->setObjectName(QStringLiteral("register_password"));
        register_password->setGeometry(QRect(190, 201, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        register_password->setFont(font2);
        register_password->setAlignment(Qt::AlignCenter);
        register_passwordAffirm = new QLabel(RegisterManager);
        register_passwordAffirm->setObjectName(QStringLiteral("register_passwordAffirm"));
        register_passwordAffirm->setGeometry(QRect(180, 310, 101, 20));
        register_passwordAffirm->setFont(font2);
        user_optionRegister = new QRadioButton(RegisterManager);
        user_optionRegister->setObjectName(QStringLiteral("user_optionRegister"));
        user_optionRegister->setGeometry(QRect(110, 550, 101, 31));
        user_optionRegister->setFont(font2);
        user_optionRegister->setChecked(true);
        academy = new QLabel(RegisterManager);
        academy->setObjectName(QStringLiteral("academy"));
        academy->setGeometry(QRect(170, 410, 101, 31));
        academy->setFont(font2);
        academy->setAlignment(Qt::AlignCenter);
        register_userNameinput = new QLineEdit(RegisterManager);
        register_userNameinput->setObjectName(QStringLiteral("register_userNameinput"));
        register_userNameinput->setGeometry(QRect(100, 140, 241, 41));
        register_userNameinput->setFont(font1);
        register_userNameinput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        affirmReisterButton = new QPushButton(RegisterManager);
        affirmReisterButton->setObjectName(QStringLiteral("affirmReisterButton"));
        affirmReisterButton->setGeometry(QRect(150, 640, 131, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        affirmReisterButton->setFont(font3);
        affirmReisterButton->setCursor(QCursor(Qt::OpenHandCursor));
        affirmReisterButton->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        register_userName = new QLabel(RegisterManager);
        register_userName->setObjectName(QStringLiteral("register_userName"));
        register_userName->setGeometry(QRect(180, 100, 81, 31));
        register_userName->setFont(font2);
        register_userName->setAlignment(Qt::AlignCenter);
        iAm = new QLabel(RegisterManager);
        iAm->setObjectName(QStringLiteral("iAm"));
        iAm->setGeometry(QRect(160, 520, 111, 21));
        iAm->setFont(font2);
        iAm->setAlignment(Qt::AlignCenter);
        academyInput = new QComboBox(RegisterManager);
        academyInput->setObjectName(QStringLiteral("academyInput"));
        academyInput->setGeometry(QRect(100, 450, 241, 41));
        academyInput->setFont(font2);
        academyInput->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;"));
        administrator_optionRegister = new QRadioButton(RegisterManager);
        administrator_optionRegister->setObjectName(QStringLiteral("administrator_optionRegister"));
        administrator_optionRegister->setGeometry(QRect(240, 550, 101, 31));
        administrator_optionRegister->setFont(font2);

        retranslateUi(RegisterManager);

        QMetaObject::connectSlotsByName(RegisterManager);
    } // setupUi

    void retranslateUi(QWidget *RegisterManager)
    {
        RegisterManager->setWindowTitle(QApplication::translate("RegisterManager", "Form", Q_NULLPTR));
        register_2->setText(QApplication::translate("RegisterManager", "\346\263\250\345\206\214", Q_NULLPTR));
        register_password->setText(QApplication::translate("RegisterManager", "\345\257\206\347\240\201", Q_NULLPTR));
        register_passwordAffirm->setText(QApplication::translate("RegisterManager", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        user_optionRegister->setText(QApplication::translate("RegisterManager", "\347\224\250\346\210\267", Q_NULLPTR));
        academy->setText(QApplication::translate("RegisterManager", "\346\211\200\345\234\250\345\255\246\351\231\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        register_userNameinput->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        affirmReisterButton->setText(QApplication::translate("RegisterManager", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        register_userName->setText(QApplication::translate("RegisterManager", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        iAm->setText(QApplication::translate("RegisterManager", "\350\264\246\345\217\267\347\261\273\345\236\213", Q_NULLPTR));
        academyInput->clear();
        academyInput->insertItems(0, QStringList()
         << QApplication::translate("RegisterManager", "\344\277\241\346\201\257\347\247\221\345\255\246\344\270\216\345\267\245\347\250\213\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\346\265\267\346\264\213\344\270\216\345\244\247\346\260\224\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\346\260\264\344\272\247\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\347\256\241\347\220\206\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\347\273\217\346\265\216\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\346\263\225\346\224\277\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242", Q_NULLPTR)
         << QApplication::translate("RegisterManager", "\345\214\226\345\255\246\345\214\226\345\267\245\345\255\246\351\231\242", Q_NULLPTR)
        );
        administrator_optionRegister->setText(QApplication::translate("RegisterManager", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterManager: public Ui_RegisterManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERMANAGER_H
