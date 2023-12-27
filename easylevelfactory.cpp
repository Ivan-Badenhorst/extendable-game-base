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

    auto [tc, pc, hpc] = basicControllers(w);

    //enemies models
    auto em = std::make_shared<EnemyModel>();
    auto pem = std::make_shared<PEnemyModel>();

    for (auto& enemy : w.getEnemies()) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pem->addEnemy(std::move(enemy));
        } else {
            em->addEnemy(std::move(enemy));
        }
    }

    //enemy controller
    auto ec = std::make_shared<EnemyController>();
    ec->init();
    ec->addEnemyModel(em);
    ec->addEnemyModel(pem);

    return std::make_shared<EasyLevel>(tc,  pc, hpc, ec);
}

