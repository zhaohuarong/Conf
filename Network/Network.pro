QT       += network

QT       -= gui

TARGET = Network
TEMPLATE = lib

DEFINES += NETWORK_LIBRARY

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/../obj

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        network.cpp

HEADERS += \
        network.h \
        network_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
