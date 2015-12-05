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

/**
 * @brief Player::move
 * @param direction
 * direction: -1 -> left
 * direction:  1 -> right
 */
void Player::move(int direction)
{
    qDebug () << direction;
}

void Player::shoot()
{
    qDebug () << "SHOOTED!";
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
