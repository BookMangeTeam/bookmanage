/********************************************************************************
** Form generated from reading UI file 'message_loginmistake.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_LOGINMISTAKE_H
#define UI_MESSAGE_LOGINMISTAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_message_loginMistake
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *message_loginMistake)
    {
        if (message_loginMistake->objectName().isEmpty())
            message_loginMistake->setObjectName(QStringLiteral("message_loginMistake"));
        message_loginMistake->resize(316, 176);
        label = new QLabel(message_loginMistake);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 291, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(message_loginMistake);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 130, 75, 23));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);

        retranslateUi(message_loginMistake);

        QMetaObject::connectSlotsByName(message_loginMistake);
    } // setupUi

    void retranslateUi(QDialog *message_loginMistake)
    {
        message_loginMistake->setWindowTitle(QApplication::translate("message_loginMistake", "Dialog", 0));
        label->setText(QApplication::translate("message_loginMistake", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201\357\274\201", 0));
        pushButton->setText(QApplication::translate("message_loginMistake", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class message_loginMistake: public Ui_message_loginMistake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_LOGINMISTAKE_H
