#include "EnemyManager.h"
#include <QDebug>
#include <Game.h>

extern Game * game;

EnemyManager* EnemyManager::_instance = 0;

EnemyManager::EnemyManager()
{
    activeEnemies = 0;
    timetToRespawn = 5000;
    paused = false;
}

void EnemyManager::start()
{
    this->initTimer();
    spawn();
}

void EnemyManager::stop()
{
    timer->stop();
    QList<Enemy *> enemies = game->scene->findChildren<Enemy *>();
    for (int i=0;i<enemies.count();i++) {
        (*enemies[i]).stop();
    }
}

void EnemyManager::decreaseEnemies()
{
    activeEnemies--;
}

void EnemyManager::togglePause()
{
    paused = !paused;
    QList<QGraphicsItem *> items = game->scene->items();
            qDebug () << items.count();
    QList<Enemy *> enemies = game->scene->findChildren<Enemy *>();
    qDebug() << enemies.count();
    for(int i=0;i<enemies.count();i++) {
        (*enemies[i]).setPause(paused);
    }
    if(paused) {
        timer->stop();
    } else {
        timer->start(timetToRespawn);
    }
}

EnemyManager *EnemyManager::getInstance()
{
    if (!_instance) {
        _instance = new EnemyManager();
    }
    return _instance;
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
        Enemy * enemy = new Enemy(enemyType);
        game->scene->addItem(enemy);
        activeEnemies++;
    }
}
