#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(int type, bool sound_,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int randomNumber = (rand() % 350 - 25) + 50;
    setPos(randomNumber,0);

    QString direction = ":/imgs/res/enemy_"+QString::number(type)+".png";
    setPixmap(QPixmap(direction));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the enemy every so often
    moveTimer  = new QTimer(this);
    shootTimer = new QTimer(this);

    connect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    connect(shootTimer,SIGNAL(timeout()),this,SLOT(shoot()));

    yTarget = rand() % 250;
    xTarget = rand() % 200;
    score   = (rand() % 10) + 3;

    sound        = sound_;
    bulletSound  = new QMediaPlayer();
    explodeSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/res/fireEffect.mp3"));
    explodeSound->setMedia(QUrl("qrc:/sounds/res/explodeEffect.mp3"));

    // start the timers
    shootTime = rand() % 3500 + 2000;
    moveTimer->start(50);
    shootTimer->start(shootTime);
}

Enemy::~Enemy()
{
    if (sound == true) explodeSound->play();
    game->enemyManager->removeEnemy(ID);
}

void Enemy::stop()
{
    moveTimer->stop();
    shootTimer->stop();
}

void Enemy::setPause(bool pause)
{
    if (pause) {
        moveTimer->stop();
        shootTimer->stop();
    } else {
        moveTimer->start(50);
        shootTimer->start(shootTime);
    }
}

void Enemy::toggleSound()
{
    sound = !sound;
}

void Enemy::setID(int id)
{
    ID = id;
}

int Enemy::getID()
{
    return ID;
}

int Enemy::getScore()
{
    return this->score;
}

void Enemy::move(){
    // move enemy down
    if (y() < yTarget) {
        setPos(x(),y()+5);
    } else {
        if (x() < xTarget) {
            setPos(x()+5,y());
            if (x() >= xTarget) {
                xTarget = (rand() % 350 - 25) + 50;
            }
        } else {
            setPos(x()-5,y());
            if (x() >= xTarget) {
                xTarget = (rand() % 50 - 25) + 50;
            }
        }
    }
}

void Enemy::shoot()
{
    if (sound== true) {
        bulletSound->setPosition(0);
        bulletSound->play();
    }
    Bullet * bullet = new Bullet(ENEMY);
    bullet->setPos(x()+35,y()+35);
    scene()->addItem(bullet);
}
