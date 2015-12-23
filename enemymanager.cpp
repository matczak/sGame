#include "EnemyManager.h"
#include <QDebug>
#include <Game.h>

extern Game * game;

EnemyManager::EnemyManager()
{
    activeEnemies = 0;
    timetToRespawn = 5000;
}

void EnemyManager::start()
{
    this->initTimer();
}

void EnemyManager::decreaseEnemies()
{
    activeEnemies--;
}

void EnemyManager::initTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(timetToRespawn);
}

void EnemyManager::spawn()
{
    if(activeEnemies < 3) {
        int enemyType = (rand() % 3) + 1;
        enemy = new Enemy(enemyType);
        game->scene->addItem(enemy);
        activeEnemies++;
    }
}
