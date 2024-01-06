/**
 * @file BaseEnemyModel.h
 * @brief Abstract class for enemy models in a game world.
 * 
 * Provides an abstract class for managing enemies in a game. This class declares
 * virtual methods for adding, checking, attacking, and determining the
 * status of enemies within the game world. It should be subclassed by
 * specific enemy model implementations.
 */

#ifndef ENEMYMODELINTERFACE_H
#define ENEMYMODELINTERFACE_H

#include "world.h"
#include <vector>

/**
 * @class BaseEnemyModel
 * @brief Abstract base class for enemy models.
 *
 * This class provides an interface for enemy models. It defines the
 * structure and necessary methods that all enemy models must implement
 * to be compatible with the game's architecture.
 */
class BaseEnemyModel
{
public:
    /**
     * @brief Adds a new enemy to the model.
     * 
     * @param enemy Unique pointer to an Enemy object.
     */
    virtual void addEnemy(std::unique_ptr<Enemy> enemy) = 0;

    /**
     * @brief Checks if an enemy exists at the specified location.
     * 
     * @param x The x position in the world grid.
     * @param y The y position in the world grid.
     * @return True if an enemy exists at the given position, false otherwise.
     */
    virtual bool containsEnemy(int x, int y) = 0;

    /**
     * @brief Determines if the enemy at a given location is defeated.
     * 
     * @param x The x position of the enemy.
     * @param y The y position of the enemy.
     * @return True if the enemy is defeated, false otherwise.
     */
    virtual bool isDefeated(int x, int y) = 0;

    /**
     * @brief Attacks the enemy at the specified location.
     * 
     * @param x The x position of the enemy.
     * @param y The y position of the enemy.
     * @param damage The amount of damage to deal to the enemy.
     */
    virtual void attackEnemy(int x, int y, int damage) = 0;

    /**
     * @brief Checks if all enemies are defeated.
     * 
     * @return True if all enemies are defeated, false otherwise.
     */
    virtual bool isCompleted()=0;

    /**
     * @brief Gets the type of enemy.
     * 
     * @return A string representing the type of enemy.
     * @throws std::runtime_error if the enemy type is empty.
     */
    std::string getEnemyType() const;

protected:
    std::string enemyType; ///< Protected string attribute for enemy type.
    int world_rows; ///< The number of rows in the world grid.
    int world_cols; ///< The number of columns in the world grid.
};

inline std::string BaseEnemyModel::getEnemyType() const
{
    if (enemyType.empty()) {
        throw std::runtime_error("Enemy type is empty");
    }
    return enemyType;
}


#endif // ENEMYMODELINTERFACE_H
