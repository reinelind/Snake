#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Gamewidget.h"
class GameObject
{

public:
    virtual void setX(const int) = 0;
    virtual void setY(const int) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual void setObjectTraits() = 0;

    virtual ~GameObject(){}

};



#endif // GAMEOBJECT_H
