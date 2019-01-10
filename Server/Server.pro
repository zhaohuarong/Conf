QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

DESTDIR = $$PWD/../bin
OBJECTS_DIR = $$PWD/../obj

INCLUDEPATH += $$PWD/../Network

LIBS += -L$$PWD/../bin -lNetwork

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
