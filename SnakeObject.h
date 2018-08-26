#ifndef SNAKEOBJECT_H
#define SNAKEOBJECT_H
#include "Gameobject.h"



class SnakeObject: public GameObject
{
public:

    enum DIRECTION {LEFT,UP,RIGHT,DOWN};
    SnakeObject();
    void setDir (DIRECTION);
    DIRECTION getDir ();

    int x, y;

    QColor getColor () const;

private:
    QRectF rectParams;
    QColor color;
    DIRECTION dir;
    int num;

    void setShape();
    void setColor();
    void draw();
    void setX();
    void setY();

    GameWidget* widget;

};

#endif // SNAKEOBJECT_H
