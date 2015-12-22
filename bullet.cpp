#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo.h>
#include "Enemy.h"
#include "Game.h"

extern Game * game;


Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/imgs/res/pBullet.png"));


    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::setType(bullet_type type)
{
    this->type = type;
}

int Bullet::getType()
{
    return this->type;
}


void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            if(this->getType() == ENEMY) continue;
            game->scoreManager->increase();
            game->enemyManager->decreaseEnemies();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        } else if(typeid(*(colliding_items[i])) == typeid(Player)) {
            game->health->decrease();

//            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

//            delete colliding_items[i];
            delete this;

            return;
        }

    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10*type);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
