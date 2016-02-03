#include "Health.h"
#include <QFont>
#include <Game.h>

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("ArcadeClassic",16));
}

void Health::decrease(){
    health--;
    if(health < 0) {
        game->gameOver();
        return;
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
