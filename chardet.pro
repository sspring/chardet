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
    ascii.cpp \
    big5.cpp \
    gb18030.cpp \
    gbk.cpp \
    shiftjis.cpp \
    utf8.cpp \
    iso2022_jp.cpp

HEADERS += \
    chardet.h \
    checker.h \
    iso2022_jp.h \
    ascii.h \
    big5.h \
    gb18030.h \
    gbk.h \
    shiftjis.h \
    utf8.h
