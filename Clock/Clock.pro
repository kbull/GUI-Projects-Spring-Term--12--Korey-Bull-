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
    clockviewfactory.cpp

HEADERS  += mainwindow.h \
    clockmodel.h \
    clockview.h \
    Enumerations.h \
    ISubject.h \
    clockviewfactory.h

FORMS    += mainwindow.ui
