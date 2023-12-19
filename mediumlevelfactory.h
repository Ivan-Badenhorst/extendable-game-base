#ifndef MEDIUMLEVELFACTORY_H
#define MEDIUMLEVELFACTORY_H

#include "levelfactory.h"

class MediumLevelFactory: public LevelFactory
{
public:
    MediumLevelFactory();
    std::shared_ptr<Level> createWorld() override;
};

#endif // MEDIUMLEVELFACTORY_H
