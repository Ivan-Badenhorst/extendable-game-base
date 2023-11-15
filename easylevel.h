#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include "tilecontroller.h"
#include "level.h"

class EasyLevel: public Level
{
public:
    EasyLevel(TileController& tc);
    TileController &getTileController() const override;

    void setTileController(const TileController &newTileController);

private:
    TileController& tileController;
};

#endif // EASYLEVEL_H
