#ifndef APPLEOBJECT_H
#define APPLEOBJECT_H
#include "gameobject.h"

class AppleObject: public GameObject
{
public:
    int x;
    int y;

    QRectF rectParams;
    QColor clr;
    AppleObject();
private:
    void setShape();
    void setColor();
    void draw();
    void setX();
    void setY();

};

#endif // APPLEOBJECT_H
