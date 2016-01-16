#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T20:08:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WorldEditor
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    viewer.cpp \
    window.cpp \
    data.cpp \
    object.cpp

HEADERS  += \
    viewer.h \
    window.h \
    data.h \
    object.h
