#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>


enum bullet_type {
    PLAYER = 1,
    ENEMY  = -1
};

class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(bullet_type type, QGraphicsItem * parent=0);
private slots:
    void move();
private:
    QMediaPlayer * bulletSound;
    QMediaPlayer * explodeSound;
    int type;
};

#endif // BULLET_H
