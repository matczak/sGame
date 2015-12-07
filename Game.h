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
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * scoreManager;
    Health * health;
    EnemyManager * enemyManager;

    void keyPressEvent(QKeyEvent * event);
private:
    int level;
    int life;
    void initGame();
    void setLevel(int level);
    void decreaseLife();

};

#endif
