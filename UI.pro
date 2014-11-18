#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T22:39:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PRJ3-GUI
TEMPLATE = app


SOURCES += main.cpp \
    winMain.cpp \
    winConfig.cpp \
    UI.cpp \
    cConfig.cpp \
    cOnOff.cpp \
    cAddRemove.cpp

HEADERS  += \
    winMain.h \
    winConfig.h \
    UI.h \
    cOnOff.h \
    cConfig.h \
    cAddRemove.h

FORMS    += \
    winMain.ui \
    winConfig.ui
