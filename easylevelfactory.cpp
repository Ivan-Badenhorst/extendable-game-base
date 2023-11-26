#include "easylevelfactory.h"


#include "protagonistcontroller.h"
#include "protagonistmodel.h"
#include "protagonistviewgraphical.h"

#include "TileH/tilemodel.h"
#include "TileH/tileviewgraphical.h"
#include "TileH/tilecontroller.h"

#include "easylevel.h"
#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackcontroller.h"
#include "HealthPackH/healthpackviewgraphical.h"

#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"

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


    //protagonist:
    std::unique_ptr<Protagonist> protagonistPtr = w.getProtagonist();
    auto pm = std::make_shared<ProtagonistModel>(std::move(protagonistPtr));
    auto pvg = std::make_shared<ProtagonistViewGraphical>(mw, pm);
    ProtagonistController pc(pvg,pm);

    //healthPacks
    HealthPackModel hpm(w.getHealthPacks());
    HealthPackViewGraphical hpv(mw, std::make_shared<HealthPackModel>(hpm));
    HealthPackController hpc(std::make_shared<HealthPackViewGraphical>(hpv), std::make_shared<HealthPackModel>(hpm));

    //enemies
    EnemyModel em;
    PEnemyModel pem;

    // Get enemies from the world and iterate through them
    for (auto& enemy : w.getEnemies()) {
        // Check if the enemy can be casted to PEnemy
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            // Add the enemy to PEnemyModel
            pem.addEnemy(move(enemy));
        } else {
            // Add the enemy to EnemyModel
            em.addEnemy(move(enemy));
        }
    }

    EnemyController ec;
    ec.addEnemyModel(std::make_shared<EnemyModel>(em));
    ec.addEnemyModel(std::make_shared<PEnemyModel>(pem));
    

    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc), 
                                std::make_shared<ProtagonistController>(pc), 
                                std::make_shared<HealthPackController>(hpc),
                                std::make_shared<EnemyController>(ec));

    

        return easyLevel;
    }

