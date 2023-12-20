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
    w.createWorld(":/worldmap.png", 100,10);

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
    em.setEnemyType("Enemy");
    PEnemyModel pem;
    pem.setEnemyType("PEnemy");

    for (auto& enemy : w.getEnemies()) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pem.addEnemy(std::move(enemy));
        } else {
            em.addEnemy(std::move(enemy));
        }
    }

//    // Create the enemies views
//    EnemyViewGraphical evg(mw, std::make_shared<EnemyModel>(em));
//    PEnemyViewGraphical pevg(mw, std::make_shared<PEnemyModel>(pem));

    // Create an EnemyController and add the enemies models to it
    auto ec = std::make_shared<EnemyController>();
    /*
    In order for ec to pass a shared pointer to itself to its PEnemyTimer, we need to do it
    after the EnemyController has been created. This is because the shared pointer is
    not initialized until the constructor has finished executing.
    */ 
    ec->init();
    ec->addEnemyModel(std::make_shared<EnemyModel>(em));
    ec->addEnemyModel(std::make_shared<PEnemyModel>(pem));
//    ec.addEnemyGraphicalView(std::make_shared<EnemyViewGraphical>(evg));
//    ec.addEnemyGraphicalView(std::make_shared<PEnemyViewGraphical>(pevg));
    
    /// TODO: adapt other controllers to be made shared before passed like enemycontroller
    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc), 
                                std::make_shared<ProtagonistController>(pc), 
                                std::make_shared<HealthPackController>(hpc),
                                ec);

    return easyLevel;
}

