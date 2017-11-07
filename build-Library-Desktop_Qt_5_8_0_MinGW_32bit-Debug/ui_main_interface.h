/********************************************************************************
** Form generated from reading UI file 'main_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_INTERFACE_H
#define UI_MAIN_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_main_interface
{
public:
    QLabel *label;
    QPushButton *main_search_btn;
    QLineEdit *main_search_text;
    QLabel *main_userinfo_label;
    QPushButton *main_exit_btn;

    void setupUi(QDialog *main_interface)
    {
        if (main_interface->objectName().isEmpty())
            main_interface->setObjectName(QStringLiteral("main_interface"));
        main_interface->resize(1060, 643);
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        main_interface->setFont(font);
        label = new QLabel(main_interface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 20, 241, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        main_search_btn = new QPushButton(main_interface);
        main_search_btn->setObjectName(QStringLiteral("main_search_btn"));
        main_search_btn->setGeometry(QRect(730, 290, 93, 31));
        main_search_text = new QLineEdit(main_interface);
        main_search_text->setObjectName(QStringLiteral("main_search_text"));
        main_search_text->setGeometry(QRect(300, 290, 411, 31));
        main_userinfo_label = new QLabel(main_interface);
        main_userinfo_label->setObjectName(QStringLiteral("main_userinfo_label"));
        main_userinfo_label->setGeometry(QRect(790, 20, 141, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        main_userinfo_label->setFont(font2);
        main_exit_btn = new QPushButton(main_interface);
        main_exit_btn->setObjectName(QStringLiteral("main_exit_btn"));
        main_exit_btn->setGeometry(QRect(950, 20, 93, 28));

        retranslateUi(main_interface);

        QMetaObject::connectSlotsByName(main_interface);
    } // setupUi

    void retranslateUi(QDialog *main_interface)
    {
        main_interface->setWindowTitle(QApplication::translate("main_interface", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("main_interface", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        main_search_btn->setText(QApplication::translate("main_interface", "\346\237\245\346\211\276", Q_NULLPTR));
        main_userinfo_label->setText(QApplication::translate("main_interface", "sign", Q_NULLPTR));
        main_exit_btn->setText(QApplication::translate("main_interface", "\346\263\250\351\224\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_interface: public Ui_main_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INTERFACE_H
