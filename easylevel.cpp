#include "easylevel.h"

EasyLevel::EasyLevel(TileController &tc)
    :tileController(tc)
{

}

//EasyLevel::EasyLevel()
//{


//}

TileController &EasyLevel::getTileController() const
{
    return tileController;
}

void EasyLevel::setTileController(const TileController &newTileController)
{
    tileController = newTileController;
}
