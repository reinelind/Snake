#ifndef MENU_H
#define MENU_H

#endif // MENU_H
#include "State.h"
#include "Gamewidget.h"

class Menu: public State
{

    enum MENU_ITEM {START, HIGHSCORES, QUIT};
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);
    Menu();

private:
    MENU_ITEM menuItem;
    QPainter *painter;
    QImage *background,*pointer;
};
