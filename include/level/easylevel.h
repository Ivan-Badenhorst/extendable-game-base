#ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <memory>

#include "tilecontroller.h"
#include "healthpackcontroller.h"
#include "level.h"
#include "protagonistcontroller.h"
#include "enemycontroller.h"

/**
 * @class EasyLevel
 * @brief Class representing an easy level in the game.
 *
 * This class implements Level and provides implementations for the
 * methods to get controllers for tiles, health packs, the protagonist, and enemies.
 */
class EasyLevel: public Level
{
public:

    /**
     * @brief Constructor that initializes the controllers for this EasyLevel.
     * @param tc Shared pointer to the TileController.
     * @param pc Shared pointer to the ProtagonistController.
     * @param hpc Shared pointer to the HealthPackController.
     * @param ec Shared pointer to the EnemyController.
     */
    EasyLevel(std::shared_ptr<TileController> tc, 
        std::shared_ptr<ProtagonistController> pc, 
        std::shared_ptr<HealthPackController>hpc,
        std::shared_ptr<EnemyController> ec);

    /**
     * @brief Getter for TileController for this level.
     * @return Shared pointer to the TileController.
     */
    std::shared_ptr<TileController> getTileController() const override;
    
    /**
     * @brief Getter for HealthPackController for this level.
     * @return Shared pointer to the HealthPackController.
     */
    std::shared_ptr<HealthPackController> getHpController() const override;
    
    /**
     * @brief Get the ProtagonistController for this level.
     * @return Shared pointer to the ProtagonistController.
     */
    std::shared_ptr<ProtagonistController> getProtController() const override;

    /**
     * @brief Get the EnemyController for this level.
     * @return Shared pointer to the EnemyController.
     */
    std::shared_ptr<EnemyController> getEnemyController() const override;

private:
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<ProtagonistController> protController;
    std::shared_ptr<HealthPackController> hpController;
    std::shared_ptr<EnemyController> enemyController;
};

#endif // EASYLEVEL_H
