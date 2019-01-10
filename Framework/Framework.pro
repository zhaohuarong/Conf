QT       -= gui

TARGET = Framework
TEMPLATE = lib

DEFINES += FRAMEWORK_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/../obj

SOURCES += \
        framework.cpp

HEADERS += \
        framework.h \
        framework_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
