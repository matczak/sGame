#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
//    enemies.push_back();
}

void EnemyManager::preSetEnemies()
{

}

void EnemyManager::getOrCreateEnemy()
{

}

void EnemyManager::createEnemy()
{

}

void EnemyManager::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

