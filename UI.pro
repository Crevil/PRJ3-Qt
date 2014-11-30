#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T22:39:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PRJ3-GUI
TEMPLATE = app

target.path=/home/root

INSTALLS+=target


SOURCES += main.cpp \
    winMain.cpp \
    winConfig.cpp \
    UI.cpp \
    cConfig.cpp \
    cOnOff.cpp \
    cAddRemove.cpp \
    winConfigPar.cpp \
    winAddRemove.cpp \
    winStatus.cpp \
    winLog.cpp \
    winOnOff.cpp \
    cStatus.cpp \
    cLogView.cpp \
    log.cpp

HEADERS  += \
    winMain.h \
    winConfig.h \
    UI.h \
    cOnOff.h \
    cConfig.h \
    cAddRemove.h \
    winOnOff.h \
    winConfigPar.h \
    winAddRemove.h \
    winStatus.h \
    winLog.h \
    cStatus.h \
    cLogView.h \
    log.h

FORMS    += \
    winMain.ui \
    winConfig.ui \
    winOnOff.ui \
    winAddRemove.ui \
    winStatus.ui \
    winLog.ui \
    winConfigPar.ui
