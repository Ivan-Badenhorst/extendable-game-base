#include "easylevel.h"


EasyLevel::EasyLevel(std::shared_ptr<TileController> tc, std::shared_ptr<ProtagonistController> pc, std::shared_ptr<HealthPackController>hpm)
    :tileController(tc), protController(pc), hpController(hpm)
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

std::shared_ptr<HealthPackController> EasyLevel::getHpController() const
{
    return hpController;
}
