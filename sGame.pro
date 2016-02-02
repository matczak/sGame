#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T19:03:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sGame
TEMPLATE = app

QT += multimedia


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    EnemyManager.cpp \
    Score.cpp \
    TextManager.cpp \
    Background.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    EnemyManager.h \
    Score.h \
    TextManager.h \
    Background.h

DISTFILES +=

RESOURCES += \
    resource.qrc
