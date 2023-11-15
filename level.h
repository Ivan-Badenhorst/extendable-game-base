#ifndef LEVEL_H
#define LEVEL_H

#include "tilecontroller.h"

class Level
{
public:
    virtual ~Level() = default;
    virtual TileController& getTileController() const;


};



#endif

