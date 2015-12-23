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
    void destroy();
    int getScore();
private:
    int yTarget;
    int xTarget;
    int score;
private slots:
    void move();
    void shoot();

};

#endif // ENEMY_H
