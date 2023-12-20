#ifndef LEVEL_H
#define LEVEL_H

#include "HealthPackH/healthpackcontroller.h"
#include "TileH/tilecontroller.h"
#include "enemycontroller.h"
#include "protagonistcontroller.h"

class Level
{
public:
//    Level() = default;
//    virtual ~Level(){};
    virtual std::shared_ptr<TileController> getTileController() const {};
    virtual std::shared_ptr<HealthPackController> getHpController() const = 0;
    virtual std::shared_ptr<ProtagonistController> getProtController() const = 0;
    virtual std::shared_ptr<EnemyController> getEnemyController() const = 0;

};



#endif

