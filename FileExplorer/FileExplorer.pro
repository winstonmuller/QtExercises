#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T10:09:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileExplorer
TEMPLATE = app


SOURCES += main.cpp \
    cfilesystemmodel.cpp \
    ctableview.cpp

HEADERS  += \
    cfilesystemmodel.h \
    ctableview.h

FORMS    += mainwindow.ui
