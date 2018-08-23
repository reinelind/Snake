#include "SnakeObject.h"


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


void SnakeObject::setShape()
{
     QRectF sampleRectangle (x, y, 10, 10);
     rectParams = sampleRectangle;
}

void SnakeObject::setColor()
{
    QColor sampleColor(Qt::white);
    clr = sampleColor;
}




