#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo.h>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QDebug>

extern Game * game;

Bullet::Bullet(bullet_type type, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer();
    explodeSound = new QMediaPlayer();

    bulletSound->setMedia(QUrl("qrc:/sounds/res/fireEffect.mp3"));
    explodeSound->setMedia(QUrl("qrc:/sounds/res/explodeEffect.mp3"));

    bulletSound->play();

    switch(type) {
        case 1: setPixmap(QPixmap(":/imgs/res/pBullet.png"));break;
        case -1: setPixmap(QPixmap(":/imgs/res/eBullet.png"));break;
    }

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
    this->type = type;
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            if(this->type == ENEMY) continue;
            explodeSound->play();
            game->scoreManager->increase();
            game->enemyManager->decreaseEnemies();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        } else if(typeid(*(colliding_items[i])) == typeid(Player)) {
            explodeSound->play();
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }

    }

    setPos(x(),y()-10*type);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

