#include "easylevelfactory.h"
#include "protagonistcontroller.h"
#include "TileH/tilecontroller.h"
#include "easylevel.h"
#include "HealthPackH/healthpackcontroller.h"
#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"


EasyLevelFactory::EasyLevelFactory()
{

}

std::shared_ptr<Level> EasyLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/worldmap.png", 100,10);

    auto [tc, pc, hpc, ec] = basicControllers(w);

    return std::make_shared<EasyLevel>(tc,  pc, hpc, ec);
}

