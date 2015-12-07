#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <QObject>
#include <QTimer>

class EnemyManager: public QObject
{
    Q_OBJECT
public:
    EnemyManager();

private:
    int timetToRespawn;
    QTimer * timer;
    void initTimer();

public slots:
    void spawn();
    void test();

};

#endif // ENEMYMANAGER_H
