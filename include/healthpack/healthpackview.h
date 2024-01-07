/**
 * @file healthpackmodel.h
 * @brief Contains the HealthPackModel class.
 *
 * This file defines the HealthPackModel class, which manages the health packs
 * within the game environment. It includes functions to handle health pack data
 * and interactions.
 */

#ifndef HEALTHPACKVIEW_H
#define HEALTHPACKVIEW_H

#include "healthpackmodel.h"

/**
 * @class HealthPackView
 * @brief Abstract class representing the view for health packs in the game.
 *
 * This class defines interfaces for managing the visual representation
 * of health packs within the game environment.
 */
class HealthPackView
{
public:

    /**
     * @brief Updates the health pack view.
     */
    virtual void update() = 0;

    /**
     * @brief Updates the health pack view for a specific position.
     *
     * Pure virtual function responsible for updating the health pack view
     * for a specified row and column, indicating whether it's used or not.
     *
     * @param row The row index of the health pack.
     * @param col The column index of the health pack.
     * @param used Flag indicating if the health pack is used (default: true).
     */
    virtual void update(int row, int col,  bool used = true) = 0;

    /**
     * @brief Clears the entire health pack view.
     *
     * Pure virtual function responsible for clearing the entire health pack view.
     * Used when switching to a new view
     */
    virtual void clearView() = 0;

    /**
     * @brief Sets the health pack model for the view.
     *
     * Pure virtual function responsible for setting the health pack model
     * for the view.
     *
     * @param newHpModel Shared pointer to the new HealthPackModel.
     */
    virtual void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) = 0;

protected:
    std::shared_ptr<HealthPackModel> hpModel; /**< Shared pointer to the associated HealthPackModel. */

};

#endif // HEALTHPACKVIEW_H
