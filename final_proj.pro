QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dots
TEMPLATE = app


SOURCES += main.cpp\
        dot_game.cpp \
        main_menu.cpp

HEADERS  += dot_game.h \
            main_menu.h

FORMS    += dot_game.ui \
            main_menu.ui
