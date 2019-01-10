QT       += multimedia

QT       -= gui

TARGET = Audio
TEMPLATE = lib

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/../obj

DEFINES += AUDIO_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        audio.cpp

HEADERS += \
        audio.h \
        audio_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
