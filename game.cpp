#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    this->initGame();
    show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        player->move(-1);
    } else if (event->key() == Qt::Key_Right) {
        player->move(1);
    } else if (event->key() == Qt::Key_Space) {
        player->shoot();
    }
}

void Game::initGame()
{
    // init class
    scene        = new QGraphicsScene();
    enemyManager = new EnemyManager();
    player       = new Player();
    scoreManager = new Score();
    health       = new Health();

    level = 0;
    score = 0;
    life  = 3;

    scene->setSceneRect(0,0,400,700);
    setBackgroundBrush(QBrush(QImage(":/imgs/res/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,700);

    // set the player
    player->setPos(400,500);
    scene->addItem(player);

    // set the score/health
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    scene->addItem(scoreManager);

    this->setLevel(1);

}

void Game::setLevel(int level)
{
    this->level = level;
}

void Game::decreaseLife()
{
    this->life--;
}
