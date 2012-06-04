#-------------------------------------------------
#
# Project created by QtCreator 2012-05-29T18:37:56
#
#-------------------------------------------------

QT       += core gui

TARGET = Clock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clockmodel.cpp \
    clockview.cpp \
    clockcontroller.cpp \
    bcdupdater.cpp \
    decupdater.cpp \
    analogview.cpp \
    binaryview.cpp \
    digitalview.cpp

HEADERS  += mainwindow.h \
    clockmodel.h \
    clockview.h \
    Enumerations.h \
    IController.h \
    clockcontroller.h \
    IUpdater.h \
    bcdupdater.h \
    decupdater.h \
    UpdaterFactory.h \
    analogview.h \
    binaryview.h \
    digitalview.h \
    ViewFactory.h

FORMS    += mainwindow.ui
