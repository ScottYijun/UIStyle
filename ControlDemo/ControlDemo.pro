#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T16:11:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlDemo
TEMPLATE = app

INCLUDEPATH += ControlStyle/

SOURCES += main.cpp\
        MainWidget.cpp \
    ControlStyle/SYPushButton.cpp

HEADERS  += MainWidget.h \
    ControlStyle/SYPushButton.h

FORMS    += MainWidget.ui

RESOURCES += \
    res.qrc
