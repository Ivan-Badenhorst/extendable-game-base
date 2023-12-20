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

    auto [tc, pc, hpc] = basicControllers(w);

    //enemies models
    auto em = std::make_shared<EnemyModel>();
    em->setEnemyType("Enemy");
    auto pem = std::make_shared<PEnemyModel>();
    pem->setEnemyType("PEnemy");

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

    return std::make_shared<HardLevel>(tc,  pc, hpc, ec);

}
