#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <Bullet.h>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int type, QGraphicsItem * parent=0);
    ~Enemy();
    void stop();
    void setPause(bool pause);
    int getScore();
private:
    int yTarget;
    int xTarget;
    int score;
    int shootTime;
    bool paused;
    QTimer * moveTimer;
    QTimer * shootTimer;
private slots:
    void move();
    void shoot();

};

#endif // ENEMY_H
