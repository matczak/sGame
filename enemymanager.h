#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <Enemy.h>

class EnemyManager: public QObject
{
    Q_OBJECT
public:
    EnemyManager();

private:
    int timetToRespawn;
    int activeEnemies;
    QTimer * timer;
    Enemy * enemy;
    void initTimer();

public slots:
    void spawn();

};

#endif // ENEMYMANAGER_H
