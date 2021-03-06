#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "EnemyManager.h"
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "TextManager.h"
#include "Background.h"

class Game:public QGraphicsView {

public:
    Game();
    QGraphicsScene * scene;
    Player         * player;
    Score          * scoreManager;
    Health         * health;
    EnemyManager   * enemyManager;
    TextManager    * textManager;
    Background     * background;

    void keyPressEvent(QKeyEvent * event);
    void gameOver();

private:
    int life;
    void initGame();
    void setLevel(int level);
    void decreaseLife();
    void pause();
    void toggleMusic();
    QMediaPlayer         * music;
    QPushButton          * button;
    QGraphicsProxyWidget * test;

private slots:
    void startGame();
};

#endif
