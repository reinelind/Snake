#include "AppleObject.h"
#include "stdlib.h"
#include "time.h"


AppleObject::AppleObject()
{
    srand(time(NULL));
}

QRectF AppleObject::getRect() const
{
    return rectParams;
}

void AppleObject::draw()
{

}

QColor AppleObject::getColor () const
{
    return color;
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
    color=sampleColor;
}

