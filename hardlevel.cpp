#include "hardlevel.h"

HardLevel::HardLevel(std::shared_ptr<TileController> tc,
                     std::shared_ptr<ProtagonistController> pc,
                     std::shared_ptr<HealthPackController>hpm,
                     std::shared_ptr<EnemyController> ec)
    :tileController(tc), protController(pc), hpController(hpm), enemyController(ec)
{

}

std::shared_ptr<TileController> HardLevel::getTileController() const
{
    return tileController;
}


std::shared_ptr<ProtagonistController> HardLevel::getProtController() const
{
    return protController;
}

std::shared_ptr<EnemyController> HardLevel::getEnemyController() const
{
    return enemyController;
}

std::shared_ptr<HealthPackController> HardLevel::getHpController() const
{
    return hpController;
}
