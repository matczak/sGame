#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QDebug>

Game::Game(QWidget *parent)
{
    this->initGame();
    show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        player->move(LEFT);
    } else if (event->key() == Qt::Key_Right) {
        player->move(RIGHT);
    } else if (event->key() == Qt::Key_Space) {
        player->shoot();
    } else if (event->key() == Qt::Key_P) {
        pause();
    }
}

void Game::gameOver()
{
    enemyManager->stop();
    scoreManager->stop();
}

void Game::initGame()
{
    // init class
    scene        = new QGraphicsScene();
    enemyManager = EnemyManager::getInstance();
    player       = new Player();
    scoreManager = new Score();
    health       = new Health();

    life  = 3;

    scene->setSceneRect(0,0,400,700);
    setBackgroundBrush(QBrush(QImage(":/imgs/res/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,700);

    // set the player
    player->setPos(175,600);
    scene->addItem(player);

    // set the score/health
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    scene->addItem(scoreManager);

    //TODO: add start button and connect to startGame slot!
    //add start button
//    button = new QPushButton();
//    button->setText("Start");
//    button->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));
//    scene->addWidget(button);
//    connect(button, SIGNAL(released()), this, SLOT(startGame()));

    this->startGame();

}


void Game::decreaseLife()
{
    this->life--;
}

void Game::pause()
{
    enemyManager->tooglePause();
    player->tooglePause();
}

void Game::startGame()
{
//    button->hide();
//    qDebug() << button->isHidden();
    enemyManager->start();
}
