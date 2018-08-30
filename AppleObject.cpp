#include "AppleObject.h"
#include "stdlib.h"
#include "time.h"

#include <chrono>




void AppleObject::setY(const int y)
{

    this->y=y;
}

int AppleObject::getX() const
{
    return x;
}

int AppleObject::getY() const
{
    return y;

}

QColor AppleObject::getColor() const
{
    return color;
}

QRectF AppleObject::getRect() const
{
    return rectParams;
}

void AppleObject::setX(const int x)
{

    this->x = x;
}

void AppleObject::setObjectTraits()
{
     QRectF sampleRectangle(x,y,10,10);
     rectParams=sampleRectangle;
     color = QColor(Qt::red);
}



