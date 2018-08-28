#ifndef FACTORY_H
#define FACTORY_H

#include "gameobject.h"

class Factory
{
public :
    virtual GameObject * create()  = 0;
    virtual ~Factory (){}
};

#endif // FACTORY_H
