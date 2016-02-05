#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <QObject>
#include <QTimer>
#include <Enemy.h>
#include <QMap>

class EnemyManager: public QObject
{
    Q_OBJECT
public:
    void start();
    void stop();
    void decreaseEnemies();
    void togglePause();
    void toggleSound();
    void removeEnemy(int id);
    static EnemyManager* getInstance();
private:
    EnemyManager();
    static EnemyManager* _instance;
    int timetToRespawn;
    int activeEnemies;
    int enemiesNumber;
    bool sound;
    bool paused;
    QTimer * timer;
    QMap <int, Enemy *> enemies;
    void initTimer();

public slots:
    void spawn();

};

#endif // ENEMYMANAGER_H
