#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H

#include "gameobject.h"
#include "SnakeObject.h"

#include "factory.h"

class SnakeFactory final : public Factory
{
public:
    GameObject * create();
};

#endif // SNAKEFACTORY_H
