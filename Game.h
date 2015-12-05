#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "EnemyManager.h"

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    void keyPressEvent(QKeyEvent * event);
};

#endif
