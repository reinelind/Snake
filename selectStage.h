#ifndef SELECTSTAGE_H
#define SELECTSTAGE_H
#include "State.h"


class SelectStage final: public State
{
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);

    SelectStage();
    int MenuItem=1;
private:
    QPainter *painter;
    QImage *background,*pointer;
};

#endif // SELECTSTAGE_H
