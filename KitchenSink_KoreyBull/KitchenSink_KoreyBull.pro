#-------------------------------------------------
#
# Project created by QtCreator 2012-05-06T20:53:02
#
#-------------------------------------------------

QT       += core gui

TARGET = KitchenSink_KoreyBull
TEMPLATE = app


SOURCES += main.cpp\
        kitchensink.cpp \
    tabpage.cpp \
    intropage.cpp \
    widgetpage.cpp \
    panelpage.cpp \
    popuppage.cpp \
    textpage.cpp \
    listpage.cpp \
    popdialog.cpp \
    sinkmodel.cpp \
    filereader.cpp

HEADERS  += kitchensink.h \
    tabpage.h \
    intropage.h \
    Enumerations.h \
    widgetpage.h \
    panelpage.h \
    popuppage.h \
    textpage.h \
    listpage.h \
    popdialog.h \
    sinkmodel.h \
    filereader.h

FORMS    += kitchensink.ui \
    popdialog.ui

OTHER_FILES += \
    introStyle.qss \
    toolboxIcon.png \
    widgetStyle.qss \
    jimmy.jpg \
    html/widget.html \
    html/text.html \
    html/popup.html \
    html/panel.html \
    html/list.html \
    html/intro.html \
    input_files/inputStrs.txt

RESOURCES += \
    KitchenSink_KoreyBull.qrc
