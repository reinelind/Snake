#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gamewidget.h"
class GameObject
{

public:
   void create()
    {
        setX();
        setY();
        setShape();
        setColor();
        draw();
    }

private:
   virtual void setShape()=0;
   virtual void setColor()=0;
   virtual void draw()=0;
   virtual void setX()=0;
   virtual void setY()=0;

};



#endif // GAMEOBJECT_H
