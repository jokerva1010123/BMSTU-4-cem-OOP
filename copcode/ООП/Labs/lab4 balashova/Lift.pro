#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T23:01:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lift
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systemcontroller.cpp \
    elevator.cpp \
    doors.cpp \
    timer.cpp

HEADERS  += mainwindow.h \
    systemcontroller.h \
    elevator.h \
    doors.h \
    timer.h \
    exeptions.h

FORMS    += mainwindow.ui
