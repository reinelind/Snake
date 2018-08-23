#include "AppleObject.h"
#include "stdlib.h"
#include "time.h"


AppleObject::AppleObject()
{
    srand(time(NULL));
}

void AppleObject::draw()
{

}

void AppleObject::setY()
{

    y=rand()%490+50;
}

void AppleObject::setX()
{

    x=rand()%490+50;
}

void AppleObject::setShape()
{
     QRectF sampleRectangle(x,y,10,10);
     rectParams=sampleRectangle;
}

void AppleObject::setColor()
{
    QColor sampleColor(Qt::red);
    clr=sampleColor;
}

