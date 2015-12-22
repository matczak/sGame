#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int randomNumber = (rand() % 350 - 25) + 50;
    setPos(randomNumber,0);

    setPixmap(QPixmap(":/imgs/res/enemy_1.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the enemy every so often
    QTimer * moveTime  = new QTimer(this);
    QTimer * shootTime = new QTimer(this);

    connect(moveTime,SIGNAL(timeout()),this,SLOT(move()));
    connect(shootTime,SIGNAL(timeout()),this,SLOT(shoot()));

    yTarget = rand() % 250;
    xTarget = rand() % 200;

    // start the timer
    moveTime->start(50);
    shootTime->start(rand() % 3500 + 2000);
}

void Enemy::move(){
    // move enemy down
    if (y() < yTarget) {
        setPos(x(),y()+5);
    } else {
        if(x() < xTarget) {
            setPos(x()+5,y());
            if(x() >= xTarget) {
                xTarget = (rand() % 350 - 25) + 50;
            }
        } else {
            setPos(x()-5,y());
            if(x() >= xTarget) {
                xTarget = (rand() % 50 - 25) + 50;
            }
        }
    }
}

void Enemy::shoot()
{
    Bullet * bullet = new Bullet();
    bullet->setType(ENEMY);
    bullet->setPos(x()+35,y()+35);
    scene()->addItem(bullet);
}
