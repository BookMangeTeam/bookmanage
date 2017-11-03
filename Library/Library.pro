#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T08:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    register.cpp \
    main_interface.cpp \
    message_regsuccessfully.cpp

HEADERS  += mainwindow.h \
    register.h \
    main_interface.h \
    message_regsuccessfully.h

FORMS    += mainwindow.ui \
    register.ui \
    main_interface.ui \
    message_regsuccessfully.ui
QT += sql
