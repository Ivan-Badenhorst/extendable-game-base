#include "hardlevelfactory.h"
#include "hardlevel.h"
#include "protagonistcontroller.h"
#include "tilecontroller.h"
#include "healthpackcontroller.h"
#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"
#include "prison.h"

#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

HardLevelFactory::HardLevelFactory()
{
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));
}

std::shared_ptr<Level> HardLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/map/worldmap.png", 20, 20);

    Prison p(w.getTiles(), w.getEnemies(), w.getHealthPacks(), w.getRows(), w.getCols());


    auto [tc, pc, hpc, ec] = basicControllers(p);
    // Add XEnemies here
    ec->addXEnemy(2);


    return std::make_shared<HardLevel>(tc,  pc, hpc, ec);

}
