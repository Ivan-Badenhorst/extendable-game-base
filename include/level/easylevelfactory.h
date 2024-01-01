#ifndef EASYLEVELFACTORY_H
#define EASYLEVELFACTORY_H

#include "levelfactory.h"


class EasyLevelFactory: public LevelFactory
{
public:
    EasyLevelFactory();
    std::shared_ptr<Level> createWorld() override;

};

#endif // EASYLEVELFACTORY_H
