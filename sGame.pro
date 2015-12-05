#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T19:03:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sGame
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h

DISTFILES +=

RESOURCES += \
    resource.qrc
