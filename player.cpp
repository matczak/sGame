#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <QDebug>


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/imgs/res/ship.png"));

    // time to shoot
    timer.start();
}

void Player::move(direction dir)
{
    if( dir == LEFT) {
        setPos(x()-10, y());
    } else if (dir == RIGHT) {
        setPos(x()+10, y());
    }
}

void Player::shoot()
{
    if(timer.elapsed() > 500 ) {
        Bullet * bullet = new Bullet();
        bullet->setType(PLAYER);
        bullet->setPos(x()+30,y()-20);
        scene()->addItem(bullet);
        timer.restart();
    }

}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
