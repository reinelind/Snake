#ifndef STATE_H
#define STATE_H

#include "gamewidget.h"

class State : public QObject
{

public:
    virtual void mousePressEvent(GameWidget*, QMouseEvent *)=0;
    virtual void BackgroundLoad (GameWidget *)=0;
    virtual void keyPressEvent(GameWidget*,QKeyEvent*)=0;
};

#endif // STATE_H
