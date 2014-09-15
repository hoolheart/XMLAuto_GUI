#-------------------------------------------------
#
# Project created by QtCreator 2014-08-09T13:53:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XMLAuto_GUI
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    datastr.cpp \
    funs.cpp \
    ZtTable/ZtTable.cpp

HEADERS  += dialog.h \
    datastr.h \
    funs.h \
    publics.h \
    ZtTable/ZtTable.h

FORMS    += dialog.ui
