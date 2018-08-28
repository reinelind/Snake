#include "AppleFactory.h"

GameObject * AppleFactory::create()
{
    return new AppleObject;
}
