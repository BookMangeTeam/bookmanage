#-------------------------------------------------
#
# Project created by QtCreator 2017-11-09T08:39:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TEST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    register.cpp \
    mainwindow_manage.cpp \
    systemmanage.cpp

HEADERS  += mainwindow.h \
    login.h \
    register.h \
    mainwindow_manage.h \
    global_variable.h \
    b_plus_tree.h \
    initial.h \
    systemmanage.h

FORMS    += mainwindow.ui \
    login.ui \
    register.ui \
    mainwindow_manage.ui \
    systemmanage.ui

RESOURCES += \
    picture.qrc
