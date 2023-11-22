#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <memory>

#include "tilecontroller.h"
#include "HealthPackH/healthpackcontroller.h"
#include "level.h"

class EasyLevel: public Level
{
public:
    EasyLevel(std::shared_ptr<TileController> tc, std::shared_ptr<HealthPackController>hpc);
    std::shared_ptr<TileController> getTileController() const override;

    void setTileController(std::shared_ptr<TileController> newTileController);

    std::shared_ptr<HealthPackController> getHpController() const;

private:
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<HealthPackController> hpController;
};

#endif // EASYLEVEL_H
