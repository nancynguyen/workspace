#-------------------------------------------------
#
# Project created by QtCreator 2014-08-24T22:27:36
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gpio.cpp

HEADERS  += mainwindow.h \
    gpio.h

FORMS    += mainwindow.ui


