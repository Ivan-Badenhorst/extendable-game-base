#include "hardlevelfactory.h"
#include "hardlevel.h"
#include "protagonistcontroller.h"
#include "TileH/tilecontroller.h"
#include "HealthPackH/healthpackcontroller.h"
#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"

HardLevelFactory::HardLevelFactory()
{

}

std::shared_ptr<Level> HardLevelFactory::createWorld()
{
    ///ADD X ENEMY IN HERE
    World w;
    w.createWorld(":/worldmap4.png", 100, 10);

    auto [tc, pc, hpc, ec] = basicControllers(w);

    return std::make_shared<HardLevel>(tc,  pc, hpc, ec);

}
