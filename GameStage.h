#ifndef GAMESTAGE_H
#define GAMESTAGE_H
#include "State.h"
#include "Gamewidget.h"
#include "SnakeObject.h"
#include "AppleObject.h"

#include <deque>


class GameStage: public State
{

    Q_OBJECT
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);

    void RunGame();
    void setHighscore();

    GameStage(int i);


private:

    void createBlock ();

    int Speed;
    QPainter *painter;
    QImage *background;
    std::vector <SnakeObject> snkVec;
    SnakeObject snake;
    AppleObject * apple;
    QTimer *timer;

    unsigned int score;
    bool entered;

private slots:

    void moveSnake();

signals:
    void SignalWidgetUpdate (GameWidget*);
};




#endif // GAMESTAGE_H
