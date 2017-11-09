/********************************************************************************
** Form generated from reading UI file 'mainwins.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINS_H
#define UI_MAINWINS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWins
{
public:
    QLabel *label;
    QPushButton *search_btn;
    QTableWidget *mainTableWidget;
    QPushButton *return_btn;
    QPushButton *renew_btn;
    QPushButton *checkHistory_btn;
    QPushButton *pushButton;
    QPushButton *money_btn;

    void setupUi(QWidget *MainWins)
    {
        if (MainWins->objectName().isEmpty())
            MainWins->setObjectName(QStringLiteral("MainWins"));
        MainWins->resize(1077, 670);
        MainWins->setCursor(QCursor(Qt::ArrowCursor));
        MainWins->setStyleSheet(QStringLiteral(""));
        label = new QLabel(MainWins);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 0, 251, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(24);
        label->setFont(font);
        search_btn = new QPushButton(MainWins);
        search_btn->setObjectName(QStringLiteral("search_btn"));
        search_btn->setGeometry(QRect(950, 180, 101, 28));
        search_btn->setAutoFillBackground(false);
        search_btn->setStyleSheet(QStringLiteral(""));
        mainTableWidget = new QTableWidget(MainWins);
        mainTableWidget->setObjectName(QStringLiteral("mainTableWidget"));
        mainTableWidget->setGeometry(QRect(150, 180, 780, 410));
        return_btn = new QPushButton(MainWins);
        return_btn->setObjectName(QStringLiteral("return_btn"));
        return_btn->setGeometry(QRect(950, 230, 101, 28));
        renew_btn = new QPushButton(MainWins);
        renew_btn->setObjectName(QStringLiteral("renew_btn"));
        renew_btn->setGeometry(QRect(950, 280, 101, 28));
        checkHistory_btn = new QPushButton(MainWins);
        checkHistory_btn->setObjectName(QStringLiteral("checkHistory_btn"));
        checkHistory_btn->setGeometry(QRect(950, 430, 101, 28));
        pushButton = new QPushButton(MainWins);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 330, 101, 28));
        money_btn = new QPushButton(MainWins);
        money_btn->setObjectName(QStringLiteral("money_btn"));
        money_btn->setGeometry(QRect(950, 380, 101, 28));

        retranslateUi(MainWins);

        QMetaObject::connectSlotsByName(MainWins);
    } // setupUi

    void retranslateUi(QWidget *MainWins)
    {
        MainWins->setWindowTitle(QApplication::translate("MainWins", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("MainWins", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        search_btn->setText(QApplication::translate("MainWins", "\345\200\237\344\271\246", Q_NULLPTR));
        return_btn->setText(QApplication::translate("MainWins", "\350\277\230\344\271\246", Q_NULLPTR));
        renew_btn->setText(QApplication::translate("MainWins", "\347\273\255\345\200\237", Q_NULLPTR));
        checkHistory_btn->setText(QApplication::translate("MainWins", "\346\237\245\347\234\213\345\200\237\344\271\246\350\256\260\345\275\225", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWins", "\346\214\202\345\244\261", Q_NULLPTR));
        money_btn->setText(QApplication::translate("MainWins", "\347\274\264\347\272\263\346\254\240\350\264\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWins: public Ui_MainWins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINS_H
