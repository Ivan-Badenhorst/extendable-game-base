#ifndef EASYLEVELFACTORY_H
#define EASYLEVELFACTORY_H

#include "levelfactory.h"

class EasyLevelFactory: public LevelFactory
{
public:
    EasyLevelFactory();
    LevelFactory createWorld() override;

    //remember to cache here when moving to next level


};

#endif // EASYLEVELFACTORY_H
