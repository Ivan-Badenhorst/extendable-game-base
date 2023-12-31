#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <memory>

#include "tilecontroller.h"
#include "healthpackcontroller.h"
#include "level.h"
#include "protagonistcontroller.h"
#include "enemycontroller.h"

class EasyLevel: public Level
{
public:

    EasyLevel(std::shared_ptr<TileController> tc, 
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

#endif // EASYLEVEL_H
