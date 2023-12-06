#include "mediumlevel.h"

MediumLevel::MediumLevel(std::shared_ptr<TileController> tc,
                         std::shared_ptr<ProtagonistController> pc,
                         std::shared_ptr<HealthPackController>hpm,
                         std::shared_ptr<EnemyController> ec)
    :tileController(tc), protController(pc), hpController(hpm), enemyController(ec)
{

}


std::shared_ptr<TileController> MediumLevel::getTileController() const
{
    return tileController;
}


std::shared_ptr<ProtagonistController> MediumLevel::getProtController() const
{
    return protController;
}

std::shared_ptr<EnemyController> MediumLevel::getEnemyController() const
{
    return enemyController;
}

std::shared_ptr<HealthPackController> MediumLevel::getHpController() const
{
    return hpController;
}
