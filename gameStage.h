#ifndef GAMESTAGE_H
#define GAMESTAGE_H
#include "State.h"
#include "Gamewidget.h"
#include "applefactory.h"
#include "gamewidget.h"
#include "snakefactory.h"
#include <deque>
#include <memory>
#include <random>


class GameStage final: public State
{
    enum DIRECTION {LEFT,UP,RIGHT,DOWN};

    Q_OBJECT
public:
    void BackgroundLoad(GameWidget *)              override;
    void mousePressEvent(GameWidget*,QMouseEvent*) override;
    void keyPressEvent(GameWidget*, QKeyEvent*)    override;

    void drawSnake();
    void RunGame();
    void setHighscore();

    GameStage(int i);

    void createBlock ();
    void setDir (DIRECTION);
    DIRECTION getDir ();

private:

    int speed;
    DIRECTION dir;

    std::unique_ptr <QPainter > painter;
    std::unique_ptr <QImage > background;
    std::vector     <GameObject*> snkVec;
    std::unique_ptr <QTimer > timer;
    std::unique_ptr <AppleFactory > appleFactory;
    std::unique_ptr <SnakeFactory > snakeFactory;
    GameObject* apple;
    GameObject* snake;

    unsigned int score;
    bool entered;

private slots:

    void moveSnake();

signals:
    void SignalWidgetUpdate (GameWidget*);
};




#endif // GAMESTAGE_H
