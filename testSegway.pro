#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T16:25:32
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11 -pg -Wno-reorder
QMAKE_LFLAGS += -pg
TRIKCONTROL_BINDIR = ../../trikRuntime/bin/arm-release
TRIKCONTROL_DIR = ../../trikRuntime/trikControl

QT       += core

QT       += gui

TARGET = testSegway
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = \
        $$PWD \
        $$BOOST_DIR \
        $$TRIKCONTROL_DIR/include \

LIBS += -L$$TRIKCONTROL_BINDIR -ltrikControl

!macx {
        QMAKE_LFLAGS += -Wl,-O2,-rpath,.
}


SOURCES += main.cpp \
    mainthread.cpp

HEADERS += \
    mainthread.h
