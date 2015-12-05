#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QElapsedTimer>
//#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void move(int direction);
    void shoot();
public slots:
    void spawn();
private:
//    QMediaPlayer * bulletsound;
    QElapsedTimer timer;
};

#endif // PLAYER_H
