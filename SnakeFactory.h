#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H

#include "gameobject.h"
#include "SnakeObject.h"

#include "factory.h"

class SnakeFactory final : public Factory
{
public:
    GameObject * create() override;
};

#endif // SNAKEFACTORY_H
