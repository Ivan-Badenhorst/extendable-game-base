/**
 * @file healthpackmodel.h
 * @brief Contains the HealthPackModel class.
 *
 * This file defines the HealthPackModel class, which manages the health packs
 * within the game environment. It includes functions to handle health pack data
 * and interactions.
 */

#ifndef HEALTHPACKMODEL_H
#define HEALTHPACKMODEL_H

#include "world.h"
#include <vector>


/**
 * @class HealthPackModel
 * @brief Manages health packs in the game environment.
 *
 * The HealthPackModel class handles the creation and management of health packs
 * within the game. It provides functionality to retrieve health pack information,
 * check for health packs at specific positions, and manage their status.
 */
class HealthPackModel
{
public:

    /**
     * @brief Constructs a HealthPackModel object using provided tiles and health value.
     *          Initializes health packs at positions corresponding to the provided tiles
     *          with the specified health value.
     * @param tiles Vector of unique pointers to Tile objects.
     * @param hpValue The value of health packs to be associated with each position.
     */
    HealthPackModel(std::vector<std::unique_ptr<Tile>> tiles, int hpValue);

    /**
     * @brief Retrieves the information of all health packs.
     * @return A vector containing arrays representing health packs' positions and values.
     *          Each array contains three integers: [xPosition, yPosition, healthValue].
     */
    std::vector<std::array<int, 3> > getHealthPacks() const;

    /**
     * @brief Checks for the presence of a health pack at the specified position.
     *          If a health pack exists at the given position and is unused, returns its value and marks it as used.
     *          Health pack values: > 0 = unused, < 0 = used, 0 = no health pack.
     * @param row Row index to check for a health pack.
     * @param col Column index to check for a health pack.
     * @return The value of the health pack at the specified position if found and unused; otherwise, returns 0.
     */
    int containsHp(int row, int col);

private:
    std::vector<std::array<int, 3>> healthPacks; /**< Vector containing arrays representing health packs.
                                              * Each array contains the x-coordinate, y-coordinate, and value of a health pack.
                                              */
};

#endif // HEALTHPACKMODEL_H
