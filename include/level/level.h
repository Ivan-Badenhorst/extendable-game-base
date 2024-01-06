#ifndef LEVEL_H
#define LEVEL_H

#include "healthpackcontroller.h"
#include "tilecontroller.h"
#include "enemycontroller.h"
#include "protagonistcontroller.h"


/**
 * @class Interface Level
 * @brief This class provides an interface for a game level. 
 * 
 * It includes methods to get controllers for
 * tiles, health packs, the protagonist, and enemies. Each specific level in the game should
 * implement this interface.
 */
class Level
{
public:
    /**
     * @brief Get the TileController for this level.
     * @return Shared pointer to the TileController.
     */
    virtual std::shared_ptr<TileController> getTileController() const = 0;

    /**
     * @brief Get the HealthPackController for this level.
     * @return Shared pointer to the HealthPackController.
     */
    virtual std::shared_ptr<HealthPackController> getHpController() const = 0;

    /**
     * @brief Get the ProtagonistController for this level.
     * @return Shared pointer to the ProtagonistController.
     */
    virtual std::shared_ptr<ProtagonistController> getProtController() const = 0;

    /**
     * @brief Get the EnemyController for this level.
     * @return Shared pointer to the EnemyController.
     */
    virtual std::shared_ptr<EnemyController> getEnemyController() const = 0;

};



#endif // LEVEL_H

