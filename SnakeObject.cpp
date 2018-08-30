#include "SnakeObject.h"


SnakeObject::SnakeObject()
    : num (3) {}

void SnakeObject::setX(const int x)
{
    this->x = x;
}
void SnakeObject::setY(const int y)
{
    this->y = y;
}

int SnakeObject::getY() const
{
    return y;
}

int SnakeObject::getX() const
{
    return x;
}

QColor SnakeObject::getColor() const
{
    return color;
}

QRectF SnakeObject::getRect() const
{
    return rectParams;
}


void SnakeObject::setObjectTraits()
{
     QRectF sampleRectangle (x, y, 10, 10);
     rectParams = sampleRectangle;
     color = QColor(Qt::GlobalColor::white);
}







