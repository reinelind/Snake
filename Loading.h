#ifndef LOADING_H
#define LOADING_H
#include "State.h"
#include "Gamewidget.h"


class Loading : public State
{
Q_OBJECT
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);

    Loading();

private:

    QPainter *painter;
    QImage *background;
    QTimer *timer;
    int xEndPos=1;

private slots:
    void TimerSlot();
};



#endif // LOADING_H
