#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score   = 0;
    stopped = false;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("ArcadeClassic",16));
}

void Score::increase(int value){
    if (stopped) return;
    score += value;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

void Score::stop()
{
    stopped = true;
}

int Score::getScore(){
    return score;
}
