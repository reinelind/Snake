#ifndef GAMESTAGE_H
#define GAMESTAGE_H
#include "state.h"
#include "gamewidget.h"
#include "SnakeObject.h"
#include "AppleObject.h"
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
    int Speed;

private:
    QPainter *painter;
    QImage *background;
    QVector <SnakeObject> s;
    SnakeObject snake;
    AppleObject* a;
    QTimer *timer;

    unsigned int score=0;
    bool Entered=false;

private slots:
    void drawSnake();


signals:
    void SignalWidgetUpdate (GameWidget*);
};




#endif // GAMESTAGE_H
