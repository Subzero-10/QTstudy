#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T12:39:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    calculatepos.cpp \
    datareceive.cpp \
    linklist.cpp

HEADERS  += widget.h \
    NrClientSDK.h \
    calculatepos.h \
    datareceive.h \
    linklist.h

FORMS    += widget.ui

win32: LIBS += -L$$PWD/./ -lNrClientSDK

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./NrClientSDK.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libNrClientSDK.a

win32: LIBS += -L$$PWD/./ -lNrClientSDK

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
