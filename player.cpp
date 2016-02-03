#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imgs/res/ship.png"));
    timer.start(); // time to shoot
    paused = false;
}

void Player::move(direction dir)
{
    if(paused) return;
    if( dir == LEFT) {
        if(x()<10) return;
        setPos(x()-10, y());
    } else if (dir == RIGHT) {
        if(x()>330)return;
        setPos(x()+10, y());
    }
}

void Player::togglePause()
{
    paused = !paused;
}

void Player::shoot()
{
    if(timer.elapsed() > 500 && !paused) {
        Bullet * bullet = new Bullet(PLAYER);
        bullet->setPos(x()+30,y()-20);
        scene()->addItem(bullet);
        timer.restart();
    }
}
