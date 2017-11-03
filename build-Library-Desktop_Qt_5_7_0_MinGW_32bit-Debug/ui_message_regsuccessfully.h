/********************************************************************************
** Form generated from reading UI file 'message_regsuccessfully.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_REGSUCCESSFULLY_H
#define UI_MESSAGE_REGSUCCESSFULLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_message_regSuccessfully
{
public:
    QLabel *reg_successfully;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *message_regSuccessfully)
    {
        if (message_regSuccessfully->objectName().isEmpty())
            message_regSuccessfully->setObjectName(QStringLiteral("message_regSuccessfully"));
        message_regSuccessfully->resize(316, 176);
        message_regSuccessfully->setMinimumSize(QSize(316, 176));
        message_regSuccessfully->setMaximumSize(QSize(316, 176));
        reg_successfully = new QLabel(message_regSuccessfully);
        reg_successfully->setObjectName(QStringLiteral("reg_successfully"));
        reg_successfully->setGeometry(QRect(60, 50, 191, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        reg_successfully->setFont(font);
        reg_successfully->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(message_regSuccessfully);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 120, 75, 31));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(message_regSuccessfully);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 120, 75, 31));
        pushButton_2->setFont(font1);

        retranslateUi(message_regSuccessfully);

        QMetaObject::connectSlotsByName(message_regSuccessfully);
    } // setupUi

    void retranslateUi(QDialog *message_regSuccessfully)
    {
        message_regSuccessfully->setWindowTitle(QApplication::translate("message_regSuccessfully", "Dialog", 0));
        reg_successfully->setText(QApplication::translate("message_regSuccessfully", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\201\357\274\201", 0));
        pushButton->setText(QApplication::translate("message_regSuccessfully", "\345\216\273\347\231\273\345\275\225", 0));
        pushButton_2->setText(QApplication::translate("message_regSuccessfully", "ok", 0));
    } // retranslateUi

};

namespace Ui {
    class message_regSuccessfully: public Ui_message_regSuccessfully {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_REGSUCCESSFULLY_H
