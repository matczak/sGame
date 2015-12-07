#include "EnemyManager.h"
#include <QDebug>

EnemyManager::EnemyManager()
{
    timetToRespawn = 5000;
    this->initTimer();
}

void EnemyManager::initTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(test()));
    timer->start(timetToRespawn);
}

void EnemyManager::spawn()
{
    qDebug () << "SPAWN!";
}

void EnemyManager::test()
{
    qDebug () << "It's working!";
}

