#include "easylevelfactory.h"


#include "protagonistcontroller.h"
#include "protagonistmodel.h"

#include "TileH/tilemodel.h"
#include "TileH/tilecontroller.h"

#include "easylevel.h"
#include "HealthPackH/healthpackmodel.h"
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
    w.createWorld(":/worldmap.png", 10,40);

    //tile
    TileModel tm;
    tm.populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    TileController tc(std::make_shared<TileModel>(tm));

    //protagonist:
    std::unique_ptr<Protagonist> protagonistPtr = w.getProtagonist();
    auto pm = std::make_shared<ProtagonistModel>(std::move(protagonistPtr));
    ProtagonistController pc(pm);

    //healthPacks
    HealthPackModel hpm(w.getHealthPacks(), 10);
    HealthPackController hpc(std::make_shared<HealthPackModel>(hpm));

    //enemies
    EnemyModel em;
    PEnemyModel pem;

    for (auto& enemy : w.getEnemies()) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pem.addEnemy(std::move(enemy));
        } else {
            em.addEnemy(std::move(enemy));
        }
    }

    EnemyController ec;
    ec.addEnemyModel(std::make_shared<EnemyModel>(em));
    ec.addEnemyModel(std::make_shared<PEnemyModel>(pem));

    auto easyLevel = std::make_shared<EasyLevel>(std::make_shared<TileController>(tc),
                                std::make_shared<ProtagonistController>(pc), 
                                std::make_shared<HealthPackController>(hpc),
                                                       std::make_shared<EnemyController>(ec));

    return easyLevel;
}

