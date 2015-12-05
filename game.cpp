#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include "EnemyManager.h"

#define test EnemyManager::instance()

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,320,700);
    setBackgroundBrush(QBrush(QImage(":/imgs/res/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(320,700);

    // create the player
    player = new Player();
    player->setPos(400,500);
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);



    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),test,SLOT(spawn()));
    timer->start(2000);

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
