#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T21:45:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openCVtest
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

SOURCES += main.cpp\
        mainwindow.cpp \
    ccombobox.cpp

HEADERS  += mainwindow.h \
    ccombobox.h

FORMS    += mainwindow.ui
