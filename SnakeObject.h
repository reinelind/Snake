#ifndef SNAKEOBJECT_H
#define SNAKEOBJECT_H
#include "gameobject.h"

class SnakeObject: public GameObject

{
public:

    int x;
    int y;
    int num=3;
    QRectF rectParams;
    QColor clr;
    enum {LEFT,UP,RIGHT,DOWN} dir = RIGHT;


private:
    void setShape();
    void setColor();
    void draw();
    void setX();
    void setY();
    GameWidget* widget;

};

#endif // SNAKEOBJECT_H
