#include "Background.h"

Background::Background()
{
    setPixmap(QPixmap(":/imgs/res/background.png"));
    yTarget = -300;
    paused = false;
}

void Background::togglePause()
{
    paused = !paused;
    if (paused) {
        timer->stop();
    } else {
        timer->start(100);
    }
}

void Background::start()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Background::move()
{
    if (y() < yTarget) {
        setPos(x(),y()+1);
        if (y() >= yTarget) {
            yTarget = 0;
        }
    } else {
        setPos(x(),y()-1);
        if (y() <= yTarget) {
            yTarget = -300;
        }
    }

}
