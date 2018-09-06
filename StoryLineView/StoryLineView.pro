CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(storylineviewplugin)
TEMPLATE    = lib

HEADERS     = storylineviewplugin.h
SOURCES     = storylineviewplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(storylineview.pri)
