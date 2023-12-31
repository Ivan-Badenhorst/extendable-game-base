#ifndef MEDIUMLEVEL_H
#define MEDIUMLEVEL_H

#include "protagonistcontroller.h"
#include "enemycontroller.h"
#include "tilecontroller.h"
#include "healthpackcontroller.h"

#include "level.h"

class MediumLevel: public Level
{
public:
    MediumLevel(std::shared_ptr<TileController> tc,
                std::shared_ptr<ProtagonistController> pc,
                std::shared_ptr<HealthPackController>hpc,
                std::shared_ptr<EnemyController> ec);

    std::shared_ptr<TileController> getTileController() const override;
    std::shared_ptr<HealthPackController> getHpController() const override;
    std::shared_ptr<ProtagonistController> getProtController() const override;
    std::shared_ptr<EnemyController> getEnemyController() const override;

private:
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<ProtagonistController> protController;
    std::shared_ptr<HealthPackController> hpController;
    std::shared_ptr<EnemyController> enemyController;
};

#endif // MEDIUMLEVEL_H
