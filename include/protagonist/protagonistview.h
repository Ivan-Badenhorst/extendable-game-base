#ifndef PROTAGONISTVIEW_H
#define PROTAGONISTVIEW_H

#include "protagonistmodel.h"
#include "qlabel.h"

/**
 * @interface ProtagonistView
 * @brief An interface for the view of the protagonist in the game.
 *
 * This provides a contract that the implementing view classes have to adhere to in order to display the protagonist.
 * It uses a shared pointer to a ProtagonistModel object to get the protagonist's state.
 */
class ProtagonistView
{
public:
    
    /**
     * @brief Generic refresh of the protagonist's view. 
     * Implicitly calls the update method with row and col after getting current position of protagonist from model.
     */
    virtual void update() = 0;

    /**
     * @brief Update the protagonist's view given position.
     * @param row The row position.
     * @param col The column position.
     */
    virtual void update(int row, int col) = 0;

    /**
     * @brief Update the protagonist's health view.
     */    
    virtual void updateHealth() = 0;

    /**
     * @brief Update the protagonist's energy view.
     */
    virtual void updateEnergy()=0;

    //animation methods

     /**
     * @brief Perform the protagonist's attack animation.
     * @param currentFrame The current frame of the animation.
     */   
    virtual void performAttack(int currentFrame)= 0;
 
     /**
     * @brief Perform the protagonist's health gain animation.
     * @param currentFrame The current frame of the animation.
     */   
    virtual void performHealthGain(int currentFrame)= 0;

    /**
     * @brief Perform the protagonist's death animation.
     * @param currentFrame The current frame of the animation.
     */
    virtual void performDeath(int currentFrame)= 0;

    /**
     * @brief Perform the protagonist's take damage animation.
     * @param currentFrame The current frame of the animation.
     */

    virtual void performTakeDamage(int currentFrame)=0;

    /**
     * @brief Clear the protagonist's view.
     */
    virtual void clearView() = 0;
    
    /**
     * @brief Set the protagonist's model.
     * @param newProtModel The new protagonist model.
     */
    virtual void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) = 0;

protected:
    std::shared_ptr<ProtagonistModel> protModel;
};


#endif
