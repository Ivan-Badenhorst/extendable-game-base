#include "easylevel.h"

EasyLevel::EasyLevel(std::shared_ptr<TileController> tc, std::shared_ptr<ProtagonistController> pc)
    :tileController(tc), protController(pc)
{

}

std::shared_ptr<TileController> EasyLevel::getTileController() const
{
    return tileController;
}

void EasyLevel::setTileController(std::shared_ptr<TileController> newTileController)
{
    tileController = newTileController;
}

std::shared_ptr<ProtagonistController> EasyLevel::getProtController() const
{
    return protController;
}
