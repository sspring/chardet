#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T19:49:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = chardet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    checker.cpp \
    asciichecker.cpp \
    big5checker.cpp \
    gb18030checker.cpp \
    gbkchecker.cpp \
    shiftjischecker.cpp \
    utf8checker.cpp

HEADERS += \
    utf8checker.h \
    gb18030checker.h \
    gbkchecker.h \
    asciichecker.h \
    chardet.h \
    checker.h \
    big5checker.h \
    shiftjischecker.h
