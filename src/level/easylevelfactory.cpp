#include "easylevelfactory.h"
#include "protagonistcontroller.h"
#include "tilecontroller.h"
#include "easylevel.h"
#include "healthpackcontroller.h"
#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"


EasyLevelFactory::EasyLevelFactory()
{

}

std::shared_ptr<Level> EasyLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/map/worldmap.png", 10,10);

    Prison p(w.getTiles(), w.getEnemies(), w.getHealthPacks(), w.getRows(), w.getCols());

    auto [tc, pc, hpc, ec] = basicControllers(p);

    // Add XEnemies here
    ec->addXEnemy(5);

    return std::make_shared<EasyLevel>(tc,  pc, hpc, ec);
}

