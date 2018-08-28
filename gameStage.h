#ifndef GAMESTAGE_H
#define GAMESTAGE_H
#include "State.h"
#include "Gamewidget.h"
#include "applefactory.h"
#include "gamewidget.h"
#include "snakefactory.h"
#include <deque>


class GameStage: public State
{
    enum DIRECTION {LEFT,UP,RIGHT,DOWN};

    Q_OBJECT
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);


    void drawSnake();
    void RunGame();
    void setHighscore();

    GameStage(int i);

    void createBlock ();
    void setDir (DIRECTION);
    DIRECTION getDir ();

private:

    int Speed;
    QPainter *painter;
    QImage *background;
    std::vector <GameObject*> snkVec;
    QTimer *timer;
    DIRECTION dir;
    AppleFactory * appleFactory;
    SnakeFactory * snakeFactory;
    GameObject * apple;
    GameObject * snake;

    unsigned int score;
    bool entered;

private slots:

    void moveSnake();

signals:
    void SignalWidgetUpdate (GameWidget*);
};




#endif // GAMESTAGE_H
