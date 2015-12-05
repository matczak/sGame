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
<<<<<<< HEAD \
    enemymanager.cpp
    Score.cpp \
    EnemyManager.cpp
=======
    Score.cpp
>>>>>>> 44aaf27b246e25f7ea975a198dc109012e9037d5

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
<<<<<<< HEAD \
    enemymanager.h
    Score.h \
    EnemyManager.h
=======
    Score.h
>>>>>>> 44aaf27b246e25f7ea975a198dc109012e9037d5

DISTFILES +=

RESOURCES += \
    resource.qrc
