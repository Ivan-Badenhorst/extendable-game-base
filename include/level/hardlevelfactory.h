#ifndef HARDLEVELFACTORY_H
#define HARDLEVELFACTORY_H

#include "levelfactory.h"

class HardLevelFactory: public LevelFactory
{
public:
    HardLevelFactory();
    std::shared_ptr<Level> createWorld() override;
};

#endif // HARDLEVELFACTORY_H
