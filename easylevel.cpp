#include "easylevel.h"

EasyLevel::EasyLevel(TileController &tc)
    :tileController(tc)
{

}

TileController &EasyLevel::getTileController() const
{
    return tileController;
}
