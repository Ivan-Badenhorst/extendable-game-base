/**
 * @file EnemyViewGraphical.h
 * @brief Graphical representation of enemies in a game environment.
 *
 * This class extends BaseEnemyView and implements EnemyView, providing
 * graphical representation for enemies. It manages rendering individual
 * enemies and updating the view based on the EnemyModel.
 */

#ifndef ENEMYVIEWGRAPHICAL_H
#define ENEMYVIEWGRAPHICAL_H
#include <memory>
#include <unordered_set>
#include "enemyview.h"
#include "baseenemyview.h"
#include "enemymodel.h"
#include "mainwindow.h"

/**
 * @class EnemyViewGraphical
 * @brief Graphical view class for Enemy in the game.
 *
 * This class is responsible for the graphical representation of enemies on the screen.
 * It handles rendering of each enemy based on the state and information provided
 * by the EnemyModel. This includes rendering individual enemies as well as updating
 * the entire view.
 */
class EnemyViewGraphical: public BaseEnemyView, public EnemyView
{
public:
    /**
     * @brief Constructor for EnemyViewGraphical.
     */
    EnemyViewGraphical();

    void render() override;
    void render(int x, int y) override;
    void clearView() override;
    void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) override;

private:
    std::shared_ptr<EnemyModel> enemyModel; ///< The EnemyModel associated with this view.
    float zValue {1}; ///< Z-value for graphical layering.
    int tileDim {50}; ///< Dimension size for tiles.

    /**
     * @brief Map of enemy positions to their graphical representations.
     * 
     * Stores a mapping from a pair of coordinates to a shared pointer
     * of QGraphicsPixmapItem representing the enemy at those coordinates.
     */
    std::map<std::pair<int, int>, std::shared_ptr<QGraphicsPixmapItem>> enemiesDisplayed;
    
    /**
     * @brief Displays an enemy at the specified coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     * @param defeated Boolean indicating whether the enemy is defeated.
     */
    void displayEnemy(int x, int y, bool defeated);
};

#endif // ENEMYVIEWGRAPHICAL_H
