#ifndef EASYLEVELFACTORY_H
#define EASYLEVELFACTORY_H

#include "levelfactory.h"


class EasyLevelFactory: public LevelFactory
{
public:
    EasyLevelFactory();
    Level* createWorld() override;

    //remember to cache here when moving to next level


};

#endif // EASYLEVELFACTORY_H
