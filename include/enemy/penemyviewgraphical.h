/**
 * @file PEnemyViewGraphical.h
 * @brief Graphical representation of P-type enemies in a game environment.
 *
 * This class extends BaseEnemyView and implements PEnemyView, providing
 * graphical representation for P-type enemies. It manages rendering individual
 * PEnemies and fire effects, as well as updating the view based on the PEnemyModel.
 */

#ifndef PENEMYVIEWGRAPHICAL_H
#define PENEMYVIEWGRAPHICAL_H
#include <memory>
#include "baseenemyview.h"
#include "penemymodel.h"
#include "penemyview.h"

/**
 * @class PEnemyViewGraphical
 * @brief Graphical view class for P-type enemies in the game.
 *
 * PEnemyViewGraphical is responsible for the graphical representation of P-type enemies on the screen.
 * It handles rendering of each PEnemy and associated fire effects based on the state and information
 * provided by the PEnemyModel. This includes rendering individual PEnemies as well as updating
 * the entire view.
 */
class PEnemyViewGraphical: public BaseEnemyView, public PEnemyView
{
public:
    /**
     * @brief Constructor for PEnemyViewGraphical.
     */
    PEnemyViewGraphical();
    
    /**
     * @brief Renders all PEnemies in the PEnemyModel.
     */
    void render() override;

    /**
     * @brief Renders a single PEnemy in the PEnemyModel at the specified coordinates.
     * @param x The x-coordinate of the PEnemy.
     * @param y The y-coordinate of the PEnemy.
     */
    void render(int x, int y) override;

    /**
     * @brief Clears the graphical view of all PEnemies and fire effects.
     */
    void clearView() override;

    /**
     * @brief Sets the PEnemyModel associated with this view.
     * @param newPenemyModel Shared pointer to the PEnemyModel to be set.
     */
    void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel) override;

private:
    std::shared_ptr<PEnemyModel> penemyModel; ///< The PEnemyModel associated with this view.

    float zValue {1}; ///< Z-value for graphical layering.
    int tileDim {50}; ///< Dimension size for tiles.

    /**
     * @brief Map of PEnemy positions to their graphical representations.
     * 
     * Stores a mapping from a pair of coordinates to a shared pointer
     * of QGraphicsPixmapItem representing the PEnemy at those coordinates.
     */
    std::map<std::pair<int, int>, std::shared_ptr<QGraphicsPixmapItem>> penemiesDisplayed;

    /**
     * @brief Map of fire positions to their graphical representations.
     * 
     * Stores a mapping from a pair of coordinates to a shared pointer
     * of QGraphicsPixmapItem representing the fire effect at those coordinates.
     */
    std::map<std::pair<int, int>, std::shared_ptr<QGraphicsPixmapItem>> firesDisplayed;

    /**
     * @brief Displays a PEnemy at the specified coordinates.
     * @param x The x-coordinate of the PEnemy.
     * @param y The y-coordinate of the PEnemy.
     * @param defeated Boolean indicating whether the PEnemy is defeated.
     */
    void displayPEnemy(int x, int y, bool defeated);

    /**
     * @brief Displays fire effects at the specified coordinates.
     * @param x The x-coordinate of the fire effect.
     * @param y The y-coordinate of the fire effect.
     */
    void displayFire(int x, int y);
};

#endif // PENEMYVIEWGRAPHICAL_H
