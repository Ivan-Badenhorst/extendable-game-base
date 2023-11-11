#ifndef LEVEL_H
#define LEVEL_H

#include "tilecontroller.h"

class Level
{
public:
    Level(TileController& tc);
    virtual TileController& getTileController();


};



#endif

