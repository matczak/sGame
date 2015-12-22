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
    Enemy(QGraphicsItem * parent=0);
    void destroy();
private:
    int yTarget;
    int xTarget;
private slots:
    void move();
    void shoot();

};

#endif // ENEMY_H
