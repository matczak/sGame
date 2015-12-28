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
    void start();
    void stop();
    void decreaseEnemies();
    void tooglePause();
private:
    int timetToRespawn;
    int activeEnemies;
    bool paused;
    QTimer * timer;
    QList <Enemy*> enemies;
    void initTimer();

public slots:
    void spawn();

};

#endif // ENEMYMANAGER_H
