#include "easylevel.h"

EasyLevel::EasyLevel(std::shared_ptr<TileController> tc)
    :tileController(tc)
{

}

//EasyLevel::EasyLevel()
//{


//}

std::shared_ptr<TileController> EasyLevel::getTileController() const
{
    return tileController;
}

void EasyLevel::setTileController(std::shared_ptr<TileController> newTileController)
{
    tileController = newTileController;
}
