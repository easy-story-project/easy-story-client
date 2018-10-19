#-------------------------------------------------
#
# Project created by QtCreator 2018-08-28T17:46:08
#
#-------------------------------------------------

QT       += core gui widgets sql

TARGET = easy-story-client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    model/story.cpp \
    thread/threadcenter.cpp \
    task/filemonitor.cpp \
    editor/storynode.cpp \
    editor/storyview.cpp \
    editor/storyscene.cpp \
    dialogs/createstorydialog.cpp \
    databases/database.cpp \
    databases/exceptions/sqlcreatefailed.cpp \
    model/actor.cpp \
    task/filesave.cpp \
    dialogs/createactordialog.cpp \
    model/chinesenamebuilder.cpp

HEADERS += \
        mainwindow.h \
    model/story.h \
    thread/threadcenter.h \
    task/filemonitor.h \
    editor/storynode.h \
    editor/storyview.h \
    editor/storyscene.h \
    define.h \
    dialogs/createstorydialog.h \
    databases/database.h \
    databases/exceptions/sqlcreatefailed.h \
    model/actor.h \
    task/filesave.h \
    dialogs/createactordialog.h \
    model/chinesenamebuilder.h

FORMS += \
        mainwindow.ui \
    dialogs/createstorydialog.ui \
    dialogs/createactordialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
