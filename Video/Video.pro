QT       += multimedia

QT       -= gui

TARGET = Video
TEMPLATE = lib

DEFINES += VIDEO_LIBRARY

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/../obj

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        video.cpp

HEADERS += \
        video.h \
        video_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
