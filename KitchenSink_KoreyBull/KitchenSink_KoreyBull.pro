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
    multiton.cpp \
    tabbuilder.cpp \
    buildstrategy.cpp \
    introstrategy.cpp \
    pagebuilder.cpp \
    widgetstrategy.cpp \
    widgetpage.cpp \
    panelstrategy.cpp \
    panelpage.cpp \
    popuppage.cpp \
    popupstrategy.cpp

HEADERS  += kitchensink.h \
    tabpage.h \
    intropage.h \
    multiton.h \
    tabbuilder.h \
    buildstrategy.h \
    introstrategy.h \
    Enumerations.h \
    pagebuilder.h \
    widgetstrategy.h \
    widgetpage.h \
    panelstrategy.h \
    panelpage.h \
    popuppage.h \
    popupstrategy.h

FORMS    += kitchensink.ui

OTHER_FILES += \
    introStyle.qss \
    toolboxIcon.png \
    html/intro.html \
    html/widget.html \
    html/text.html \
    html/popup.html \
    html/panel.html \
    html/list.html \
    widgetStyle.qss \
    jimmy.jpg

RESOURCES += \
    KitchenSink_KoreyBull.qrc
