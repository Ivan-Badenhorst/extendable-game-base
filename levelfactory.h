#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include "level.h"

class LevelFactory
{
public:
    LevelFactory();
    virtual std::shared_ptr<Level> createWorld() = 0;

protected:
    std::tuple<std::shared_ptr<TileController>, std::shared_ptr<ProtagonistController>, std::shared_ptr<HealthPackController>> basicControllers(World& w);
};

#endif // LEVELFACTORY_H
