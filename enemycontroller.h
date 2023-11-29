#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
#include "enemyviewinterface.h"
#include <memory>



/**
 * @class EnemyController
 * @brief Class responsible for controlling enemies in the game.
 */
class EnemyController {
public:
    /**
     * @brief Default constructor for EnemyController.
     */
    EnemyController();
    
    /**
     * @brief Refreshes all graphical elements related to the enemies.
     */
    void refreshAllGraphical();
    
    /**
     * @brief Adds an enemy model to the controller.
     * @param em The enemy model to be added.
     */
    void addEnemyModel(std::shared_ptr<EnemyModelInterface> em);

    /**
     * @brief Sets the enemy views for the controller.
     * @param newEnemyView The vector of enemy views to be set.
     */
    void setEnemyView(const std::vector<std::shared_ptr<EnemyViewInterface>>& newEnemyView);

    /**
     * @brief Retrieves the enemy models stored in the controller.
     * @return The vector of enemy models.
     */
    std::vector<std::shared_ptr<EnemyModelInterface>> getEnemyModels() const;

    /**
     * @brief Checks if there is an enemy at the given coordinates.
     * @param col The column to check.
     * @param row The row to check.
     * @return True if there is an enemy at the given coordinates, false otherwise.
     */
    bool containsEnemy(int col, int row) const;

    /**
     * @brief Checks if the enemy at the given coordinates has been defeated.
     * @param col The column to check.
     * @param row The row to check.
     * @return True if the enemy at the given coordinates has been defeated, false otherwise.
     */
    bool isDefeated(int col, int row) const;

    /**
     * @brief Attacks the enemy at the given coordinates.
     * @param col The column to attack.
     * @param row The row to attack.
     * @param damage The amount of damage to deal to the enemy.
     */
    void attackEnemy(int col, int row, int damage);

private:
    std::vector<std::shared_ptr<EnemyModelInterface>> enemyModels; ///< Vector of enemy models.
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews; ///< Vector of enemy views.
};


#endif // ENEMYCONTROLLER_H
