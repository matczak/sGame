#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QDebug>
#include <Bullet.h>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int type, bool sound_, QGraphicsItem * parent=0);
    ~Enemy();
    void stop();
    void setPause(bool pause);
    void toggleSound();
    void setID(int id);
    int getID();
    int getScore();
private:
    int yTarget;
    int xTarget;
    int score;
    int shootTime;
    int ID;
    bool sound;
    bool paused;
    QMediaPlayer * bulletSound;
    QMediaPlayer * explodeSound;
    QTimer * moveTimer;
    QTimer * shootTimer;
private slots:
    void move();
    void shoot();

};

#endif // ENEMY_H
