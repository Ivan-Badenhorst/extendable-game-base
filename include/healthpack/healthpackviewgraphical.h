/**
 * @file healthpackviewgraphical.h
 * @brief Defines the graphical representation of health packs in the game.
 *
 * This class manages the graphical representation of health packs within the game environment.
 * It utilizes QGraphicsScene to display health pack objects.
 */

#ifndef HEALTHPACKVIEWGRAPHICAL_H
#define HEALTHPACKVIEWGRAPHICAL_H

#include <memory>

#include "healthpackview.h"
#include "healthpackmodel.h"
#include "qgraphicsscene.h"


/**
 * @class HealthPackViewGraphical
 * @brief Graphical implementation for viewing health packs in the game.
 * Handles graphical representation and updates for health packs.
 */
class HealthPackViewGraphical: public HealthPackView
{
public:

    /**
     * @brief Default constructor for HealthPackViewGraphical.
     * Initializes a HealthPackViewGraphical instance.
     */
    HealthPackViewGraphical();

    /**
     * @brief Updates the graphical representation of all health packs.
     * Updates the graphical view to display all health packs.
     */
    void update() override;

    /**
     * @brief Updates the graphical representation of a specific health pack.
     * @param row Row index of the health pack.
     * @param col Column index of the health pack.
     * @param used Flag indicating if the health pack is used (default: true).
     * Updates the graphical view to display the health pack at the specified row and column.
     * If used is true, displays that the health pack has been used.
     */
    void update(int row, int col, bool used = true) override;

    /**
     * @brief Clears the graphical view of all health packs.
     * Clears the graphical display of all health packs.
     */
    void clearView() override;


    /**
     * @brief Sets the HealthPackModel for the graphical view.
     * @param newHpModel Shared pointer to the new HealthPackModel to be set.
     * Sets the provided HealthPackModel to the hpModel member variable.
     */
    void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) override;

    /**
     * @brief Sets the QGraphicsScene for the graphical view.
     * @param newScene Shared pointer to the new QGraphicsScene.
     * Sets the provided QGraphicsScene to the scene member variable.
     */
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

private:
    float zValue {1}; /**< Z-value for the health pack display. Default value: 1 */
    int tileDim {50}; /**< Dimension of each health pack icon. Default value: 50 */

    std::vector<std::shared_ptr<QGraphicsPixmapItem>> healthpackDisplays; /**< Vector of shared pointers to QGraphicsPixmapItem for health pack display */
    std::shared_ptr<QGraphicsScene> scene; /**< Shared pointer to the QGraphicsScene for health pack display. */

    /**
     * @brief Displays a health pack icon at the specified coordinates.
     * @param icon Shared pointer to the QGraphicsPixmapItem representing the health pack icon.
     * @param hp Array containing health pack information: [x-coordinate, y-coordinate, health value].
     */
    void displayHp(std::shared_ptr<QGraphicsPixmapItem> icon, std::array<int, 3> hp);

};

#endif // HEALTHPACKVIEWGRAPHICAL_H
