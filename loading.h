#ifndef LOADING_H
#define LOADING_H
#include "State.h"
#include "Gamewidget.h"


class Loading final : public State
{
Q_OBJECT
public:
    void BackgroundLoad(GameWidget *)              override;
    void mousePressEvent(GameWidget*,QMouseEvent*) override;
    void keyPressEvent(GameWidget*, QKeyEvent*)    override;

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
