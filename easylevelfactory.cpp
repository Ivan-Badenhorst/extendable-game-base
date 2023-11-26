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
#include "enemyviewgraphical.h"
#include "penemyviewgraphical.h"

EasyLevelFactory::EasyLevelFactory()
{

}

Level* EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 10,10);

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

    // Create one model per enemy type
    EnemyModel em;
    PEnemyModel pem;


    // Get enemies from the world and iterate through them (for Enemy and PEnemy only)
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

    // Create the enemies views
    EnemyViewGraphical evg(mw, std::make_shared<EnemyModel>(em));
    PEnemyViewGraphical pevg(mw, std::make_shared<PEnemyModel>(pem));

    // Create an EnemyController and add the enemies models to it
    EnemyController ec;
    ec.addEnemyModel(std::make_shared<EnemyModel>(em));
    ec.addEnemyModel(std::make_shared<PEnemyModel>(pem));
    ec.addEnemyGraphicalView(std::make_shared<EnemyViewGraphical>(evg));
    ec.addEnemyGraphicalView(std::make_shared<PEnemyViewGraphical>(pevg));
    

    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc), 
                                std::make_shared<ProtagonistController>(pc), 
                                std::make_shared<HealthPackController>(hpc),
                                std::make_shared<EnemyController>(ec));

    return easyLevel;
    }

