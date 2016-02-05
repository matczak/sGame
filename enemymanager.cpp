#include "EnemyManager.h"
#include <QDebug>
#include <Game.h>

extern Game * game;

EnemyManager* EnemyManager::_instance = 0;

EnemyManager::EnemyManager()
{
    enemiesNumber  = 0;
    activeEnemies  = 0;
    timetToRespawn = 5000;
    paused         = false;
    sound          = true;
}

void EnemyManager::start()
{
    this->initTimer();
    spawn();
}

void EnemyManager::stop()
{
    timer->stop();
    QMap<int, Enemy *>::iterator i;
    for(i = enemies.begin();i != enemies.end(); i++) {
        (*enemies[i.key()]).stop();
    }
}

void EnemyManager::decreaseEnemies()
{
    activeEnemies--;
}

void EnemyManager::togglePause()
{
    paused = !paused;
    QMap<int, Enemy *>::iterator i;
    for(i = enemies.begin();i != enemies.end(); i++) {
        (*enemies[i.key()]).setPause(paused);
    }
    if(paused) {
        timer->stop();
    } else {
        timer->start(timetToRespawn);
    }
}

void EnemyManager::toggleSound()
{
    sound = !sound;
    QMap<int, Enemy *>::iterator i;
    for(i = enemies.begin();i != enemies.end(); i++) {
        (*enemies[i.key()]).toggleSound();
    }
}

void EnemyManager::removeEnemy(int id)
{
    enemies.remove(id);
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
        enemiesNumber++;
        int enemyType = (rand() % 3) + 1;
        Enemy * enemy = new Enemy(enemyType, sound);
        enemy->setID(enemiesNumber);
        enemies[enemiesNumber] = enemy;
        game->scene->addItem(enemy);
        activeEnemies++;
    }
}
