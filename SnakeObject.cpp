#include "SnakeObject.h"


SnakeObject::SnakeObject()
    : num (3), dir (RIGHT) {}

void SnakeObject::setDir(SnakeObject::DIRECTION direction)
{
    dir = direction;
}

SnakeObject::DIRECTION SnakeObject::getDir()
{
    return dir;
}

void SnakeObject::draw()
{

}

void SnakeObject::setX()
{
    x = this->x;
}
void SnakeObject::setY()
{
    y = this->y;
}


QColor SnakeObject::getColor() const
{
    return color;
}

void SnakeObject::setShape()
{
     QRectF sampleRectangle (x, y, 10, 10);
     rectParams = sampleRectangle;
}

void SnakeObject::setColor()
{
    color = QColor(Qt::GlobalColor::white);

}







