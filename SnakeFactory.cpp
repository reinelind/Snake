#include "SnakeFactory.h"

GameObject * SnakeFactory::create()
{
    return new SnakeObject;
}
