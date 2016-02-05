#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QDebug>

Game::Game()
{
    this->initGame();
    show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter) {
        textManager->hideText();
        startGame();
    } else if (event->key() == Qt::Key_Left) {
        player->move(LEFT);
    } else if (event->key() == Qt::Key_Right) {
        player->move(RIGHT);
    } else if (event->key() == Qt::Key_Space) {
        player->shoot();
    } else if (event->key() == Qt::Key_P) {
        pause();
    } else if (event->key() == Qt::Key_M) {
        toggleMusic();
        player->toggleSound();
        enemyManager->toggleSound();
    }
}

void Game::gameOver()
{
    enemyManager->stop();
    QString score = QString::number(scoreManager->getScore());
    scoreManager->stop();
    textManager->showText("GAME OVER! \nScore:" + score);
}

void Game::initGame()
{
    // init class
    scene        = new QGraphicsScene();
    enemyManager = EnemyManager::getInstance();
    textManager  = new TextManager();
    player       = new Player();
    scoreManager = new Score();
    health       = new Health();
    life         = 3;

    scene->setSceneRect(0,0,400,700);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,700);

    // add font
    QFontDatabase::addApplicationFont(":/fonts/res/ARCADECLASSIC.TTF");

    // init background music
    music = new QMediaPlayer();
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/res/bgMusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->setCurrentIndex(0);
    music->setPlaylist(playlist);
    music->play();

    // set background
    background = new Background();
    scene->addItem(background);

    // set the player
    player->setPos(175,600);
    scene->addItem(player);

    // set the score/health
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    scene->addItem(scoreManager);
    scene->addItem(textManager);

    textManager->showText("Press Enter to start\n Press 'M' to ON/OFF music");
    textManager->setPos(textManager->x()+65, textManager->y()+320);
}


void Game::decreaseLife()
{
    this->life--;
}

void Game::pause()
{
    enemyManager->togglePause();
    background->togglePause();
    player->togglePause();
}

void Game::toggleMusic()
{
    if(music->state() == QMediaPlayer::PlayingState) {
        music->pause();
    } else {
        music->play();
    }
}

void Game::startGame()
{
    enemyManager->start();
    background->start();
}
