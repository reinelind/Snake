#ifndef MENU_H
#define MENU_H

#endif // MENU_H
#include "State.h"
#include "Gamewidget.h"

class Menu: public State
{
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);
    Menu();

private:
    int MenuItem;
    QPainter *painter;
    QImage *background,*pointer;
};
