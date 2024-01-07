/**
 * @file health_pack_controller.h
 * @brief Header file containing the HealthPackController class.
 *
 * This file defines the HealthPackController class responsible for managing interactions
 * between the HealthPackModel and HealthPackView in the game environment.
 */

#ifndef HEALTHPACKCONTROLLER_H
#define HEALTHPACKCONTROLLER_H

#include "healthpackmodel.h"
#include "healthpackview.h"


/**
 * @class HealthPackController
 * @brief Controller managing interactions between the HealthPackModel and HealthPackView.
 *
 * This class handles the interactions and updates between the HealthPackModel, which contains
 * the logic for health packs and provides interactions functions.
 */
class HealthPackController
{
public:

    /**
     * @brief Constructs a HealthPackController object with the provided HealthPackModel.
     * @param hpm Shared pointer to the HealthPackModel associated with the controller.
     *          Initializes the HealthPackController with the specified HealthPackModel instance.
     */
    HealthPackController(std::shared_ptr<HealthPackModel> hpm);

    /**
     * @brief Refreshes the health pack view.
     * Calls the update function in the associated view to refresh all the displayed information.
     */
    void refreshAll();

    /**
     * @brief Updates the health pack view if a health pack is present at the specified row and column.
     *          Checks if a health pack exists at the provided row and column coordinates in the model.
     *          If a health pack is found, triggers an update in the associated view for that position.
     * @param row Row index to check for a health pack.
     * @param col Column index to check for a health pack.
     * @return The value of the health pack found at the specified position (0 if no health pack found).
     */
    int update(int row, int col);//row and col are tile numbers

    /**
     * @brief Sets the view for the HealthPackController.
     *          Assigns the provided HealthPackView as the associated view for the controller.
     * @param newHpView Shared pointer to the new HealthPackView.
     */
    void setHpView(const std::shared_ptr<HealthPackView> &newHpView);

    /**
     * @brief Retrieves the HealthPackModel associated with the controller.
     * @return Shared pointer to the HealthPackModel associated with the controller.
     */
    std::shared_ptr<HealthPackModel> getHpModel() const;

private:
    std::shared_ptr<HealthPackView> hpView; /**< Shared pointer to the HealthPackView associated with the HealthPackController. */
    std::shared_ptr<HealthPackModel> hpModel; /**< Shared pointer to the HealthPackModel associated with the HealthPackController. */

};

#endif // HEALTHPACKCONTROLLER_H
