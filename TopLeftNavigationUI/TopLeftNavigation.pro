#-------------------------------------------------
#
# Project created by QtCreator 2020-02-16T10:38:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = TopLeftNavigation
TEMPLATE    = app
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     += TopLeftNavigation.cpp

HEADERS     += iconhelper.h
HEADERS     += appinit.h
HEADERS     += TopLeftNavigation.h

FORMS       += TopLeftNavigation.ui

RESOURCES   += main.qrc
RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD
