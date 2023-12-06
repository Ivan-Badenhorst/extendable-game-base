#include "easylevel.h"


EasyLevel::EasyLevel(std::shared_ptr<TileController> tc, 
    std::shared_ptr<ProtagonistController> pc, 
    std::shared_ptr<HealthPackController>hpm,
    std::shared_ptr<EnemyController> ec)
    :tileController(tc), protController(pc), hpController(hpm), enemyController(ec)
{

}

std::shared_ptr<TileController> EasyLevel::getTileController() const
{
    return tileController;
}


std::shared_ptr<ProtagonistController> EasyLevel::getProtController() const
{
    return protController;
}

std::shared_ptr<EnemyController> EasyLevel::getEnemyController() const
{
    return enemyController;
}

std::shared_ptr<HealthPackController> EasyLevel::getHpController() const
{
    return hpController;
}
