#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T21:45:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = openCVtest
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc

SOURCES += main.cpp\
        mainwindow.cpp \
    operations.cpp \
    customtab.cpp \
    operations/morphology.cpp \
    operations/cvtcolor.cpp \
    operations/function.cpp \
    operations/cannyedges.cpp \
    operations/thresholdgray.cpp


HEADERS  += mainwindow.h \
    operations.h \
    customtab.h \
    operations/morphology.h \
    operations/cvtcolor.h \
    operations/function.h \
    operations/cannyedges.h \
    operations/thresholdgray.h

FORMS    += mainwindow.ui
