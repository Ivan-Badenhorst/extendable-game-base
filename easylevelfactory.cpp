#include "easylevelfactory.h"
#include "TileH/tilemodel.h"
#include "TileH/tileviewgraphical.h"
#include "TileH/tilecontroller.h"
#include "easylevel.h"
#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackcontroller.h"
#include "HealthPackH/healthpackviewgraphical.h"

EasyLevelFactory::EasyLevelFactory()
{

}

Level* EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 0,10);

    //tile
    TileModel tm;
    tm.populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    TileViewGraphical tv(mw, std::make_shared<TileModel>(tm));
    TileController tc(std::make_shared<TileViewGraphical>(tv), std::make_shared<TileModel>(tm));

    //healthPacks
    HealthPackModel hpm(w.getHealthPacks());
    HealthPackViewGraphical hpv(mw, std::make_shared<HealthPackModel>(hpm));
    HealthPackController hpc(std::make_shared<HealthPackViewGraphical>(hpv), std::make_shared<HealthPackModel>(hpm));

    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc), std::make_shared<HealthPackController>(hpc));

    return easyLevel;
}

