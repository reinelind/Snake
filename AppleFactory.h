#ifndef APPLEFACTORY_H
#define APPLEFACTORY_H

#include "gameobject.h"
#include "factory.h"
#include "AppleObject.h"



class AppleFactory final : public Factory
{
public:
    GameObject * create() override;

};

#endif // APPLEFACTORY_H
