#ifndef SELECTSTAGE_H
#define SELECTSTAGE_H
#include "State.h"


class SelectStage final: public State
{
    enum SELECT_ITEM {EASY, MEDIUM, HARD};
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);

    SelectStage();
private:

    SELECT_ITEM menuItem;
    QPainter *painter;
    QImage *background,*pointer;
};

#endif // SELECTSTAGE_H
