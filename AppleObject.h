#ifndef APPLEOBJECT_H
#define APPLEOBJECT_H
#include "Gameobject.h"


class AppleObject: public GameObject
{

public:
    int x,y;
    AppleObject();
    QColor getColor() const;
    QRectF getRect() const;



private:

    QRectF rectParams;
    QColor color;

    void setShape();
    void setColor();
    void draw();
    void setX();
    void setY();

};

#endif // APPLEOBJECT_H
