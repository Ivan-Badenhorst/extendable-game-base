#ifndef LEVEL_H
#define LEVEL_H

#include "TileH/tilecontroller.h"

class Level
{
public:
//    Level() = default;
//    virtual ~Level(){};
    virtual std::shared_ptr<TileController> getTileController() const {};


};



#endif

