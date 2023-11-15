#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <memory>

#include "tilecontroller.h"
#include "level.h"

class EasyLevel: public Level
{
public:
    EasyLevel(std::shared_ptr<TileController> tc);
    std::shared_ptr<TileController> getTileController() const override;

    void setTileController(std::shared_ptr<TileController> newTileController);

private:
    std::shared_ptr<TileController> tileController;
};

#endif // EASYLEVEL_H
