#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


enum bullet_type {
    PLAYER = 1,
    ENEMY  = -1
};

class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
    void setType(bullet_type type);
    int getType();
public slots:
    void move();
private:
    int type;
};

#endif // BULLET_H
