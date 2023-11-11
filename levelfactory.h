#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include "world.h"
class LevelFactory
{
public:
    LevelFactory();
    virtual LevelFactory createWorld();
};

#endif // LEVELFACTORY_H
