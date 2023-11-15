#ifndef LEVEL_H
#define LEVEL_H

#include "tilecontroller.h"

class Level
{
public:
    Level() = default;
    virtual ~Level(){};
    virtual TileController& getTileController() const;


};



#endif

