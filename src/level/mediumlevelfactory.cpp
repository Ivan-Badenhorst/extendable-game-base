#include "mediumlevelfactory.h"
#include "mediumlevel.h"

#include "protagonistcontroller.h"
#include "tilecontroller.h"

#include "healthpackcontroller.h"

#include "enemycontroller.h"
#include "enemymodel.h"
#include "penemymodel.h"


MediumLevelFactory::MediumLevelFactory()
{

}

std::shared_ptr<Level> MediumLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/map/worldmap.png", 20, 20);

    Prison p(w.getTiles(), w.getEnemies(), w.getHealthPacks(), w.getRows(), w.getCols());

    auto [tc, pc, hpc, ec] = basicControllers(p);

    return std::make_shared<MediumLevel>(tc,  pc, hpc, ec);
}
