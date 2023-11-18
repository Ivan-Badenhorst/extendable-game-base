#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <memory>

#include "tilecontroller.h"
#include "level.h"
#include "protagonistcontroller.h"

class EasyLevel: public Level
{
public:
    EasyLevel(std::shared_ptr<TileController> tc, std::shared_ptr<ProtagonistController> pc);
    std::shared_ptr<TileController> getTileController() const override;

    void setTileController(std::shared_ptr<TileController> newTileController);

    std::shared_ptr<ProtagonistController> getProtController() const;

private:
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<ProtagonistController> protController;
};

#endif // EASYLEVEL_H
