/********************************************************************************
** Form generated from reading UI file 'systemmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGE_H
#define UI_SYSTEMMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemManage
{
public:
    QPushButton *oneKeyImport;
    QPushButton *oneKeyDelete;
    QLabel *label;
    QPushButton *returnBtn;

    void setupUi(QWidget *SystemManage)
    {
        if (SystemManage->objectName().isEmpty())
            SystemManage->setObjectName(QStringLiteral("SystemManage"));
        SystemManage->resize(325, 484);
        SystemManage->setStyleSheet(QStringLiteral("background:#fff"));
        oneKeyImport = new QPushButton(SystemManage);
        oneKeyImport->setObjectName(QStringLiteral("oneKeyImport"));
        oneKeyImport->setGeometry(QRect(90, 200, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        oneKeyImport->setFont(font);
        oneKeyImport->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        oneKeyDelete = new QPushButton(SystemManage);
        oneKeyDelete->setObjectName(QStringLiteral("oneKeyDelete"));
        oneKeyDelete->setGeometry(QRect(90, 270, 141, 31));
        oneKeyDelete->setFont(font);
        oneKeyDelete->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));
        label = new QLabel(SystemManage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 161, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(24);
        label->setFont(font1);
        returnBtn = new QPushButton(SystemManage);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(120, 390, 81, 31));
        returnBtn->setFont(font);
        returnBtn->setStyleSheet(QStringLiteral("border:2px groove rgb(44, 62, 80);border-radius:10px;padding:2px 4px;background-color:rgb(44, 62, 80);color:#fff;"));

        retranslateUi(SystemManage);

        QMetaObject::connectSlotsByName(SystemManage);
    } // setupUi

    void retranslateUi(QWidget *SystemManage)
    {
        SystemManage->setWindowTitle(QApplication::translate("SystemManage", "Form", Q_NULLPTR));
        oneKeyImport->setText(QApplication::translate("SystemManage", "\344\270\200\351\224\256\345\257\274\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        oneKeyDelete->setText(QApplication::translate("SystemManage", "\344\270\200\351\224\256\346\270\205\347\251\272\346\225\260\346\215\256", Q_NULLPTR));
        label->setText(QApplication::translate("SystemManage", "\347\263\273\347\273\237\346\223\215\344\275\234", Q_NULLPTR));
        returnBtn->setText(QApplication::translate("SystemManage", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SystemManage: public Ui_SystemManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGE_H
