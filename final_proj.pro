QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dots
TEMPLATE = app


SOURCES += main.cpp\
        dot_game.cpp

HEADERS  += dot_game.h

FORMS    += dot_game.ui
