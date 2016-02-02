#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QDebug>

class Background: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    Background();
    void togglePause();
     void start();
private:
    bool paused;
    int yTarget;
    QTimer * timer;
private slots:
    void move();
};

#endif // BACKGROUND_H
