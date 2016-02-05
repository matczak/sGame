#include "Player.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/imgs/res/ship.png"));
    timer.start(); // time to shoot
    paused = false;
    sound = true;
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/res/fireEffect.mp3"));
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

void Player::toggleSound()
{
    sound = !sound;
}

void Player::shoot()
{
    if(timer.elapsed() > 500 && !paused) {
        if(sound== true) {
            bulletSound->setPosition(0);
            bulletSound->play();
        }
        Bullet * bullet = new Bullet(PLAYER);
        bullet->setPos(x()+30,y()-20);
        scene()->addItem(bullet);
        timer.restart();
    }
}
