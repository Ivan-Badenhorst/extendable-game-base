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
    w.createWorld(":/map/worldmap.png", 100,100);

    auto [tc, pc, hpc, ec] = basicControllers(w);

    return std::make_shared<MediumLevel>(tc,  pc, hpc, ec);
}
