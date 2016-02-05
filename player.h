#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QElapsedTimer>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "Enemy.h"

enum direction {
    LEFT  = -1,
    RIGHT = 1
};

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void move(direction direction);
    void togglePause();
    void toggleSound();
    void shoot();
private:
    bool sound;
    bool paused;
    QMediaPlayer * bulletSound;
    QElapsedTimer timer;

};

#endif // PLAYER_H
