#ifndef PROTAGONISTVIEWGRAPHICAL_H
#define PROTAGONISTVIEWGRAPHICAL_H

#include "graphicalgameview.h"
#include "protagonistview.h"
#include "protagonistmodel.h"

/**
 * @class ProtagonistViewGraphical
 * @brief A graphical view for the protagonist in the game.
 *
 * This class is responsible for updating and animating the protagonist's graphical view.
 * It uses a shared pointer to a ProtagonistModel object to get the protagonist's state.
 * It implements the ProtagonistView interface.
 */
class ProtagonistViewGraphical : public ProtagonistView
{
public:
    /**
     * @brief Default constructor.
     */
    ProtagonistViewGraphical();

    /**
     * @brief Generic refresh of the protagonist's view. 
     * Implicitly updates protagonist view based on current position of protagonist from model.
     */
    void update() override;

    /**
     * @brief Update the protagonist's graphical view given position.
     * 
     * Takes into account the state of the protagonist i.e. in danger zone or not.
     * 
     * @param row The row position.
     * @param col The column position.
     */
    void update(int row, int col) override;

    /**
     * @brief Update the protagonist's health bar view.
     */
    void updateHealth() override;
    
    /**
     * @brief Update the protagonist's energy bar view.
     */
    void updateEnergy() override;


//animation methods

    /**
     * @brief Perform the protagonist's attack animation.
     * Retrieve appropriate resource and display it on the scene.
     * @param currentFrame The current frame of the animation.
     */
    void performAttack(int currentFrame) override;
    
    /**
     * @brief Perform the protagonist's health gain animation.
     * @param currentFrame The current frame of the animation.
     */
    void performHealthGain(int currentFrame) override;
    
    /**
     * @brief Perform the protagonist's death animation.
     * @param currentFrame The current frame of the animation.
     */
    void performDeath(int currentFrame) override;

     /**
     * @brief Perform the protagonist's take damage animation.
     * @param currentFrame The current frame of the animation.
     */   
    void performTakeDamage(int currentFrame) override;

//setters

    /**
     * @brief Set the protagonist's health bar.
     * @param newHealthBar The new health bar.
     */
    void setHealthBar(const std::shared_ptr<HealthProgressBar> newHealthBar);

    /**
     * @brief Set the protagonist's energy bar.
     * @param newEnergyBar The new energy bar.
     */
    void setEnergyBar(const std::shared_ptr<EnergyProgressBar> newEnergyBar);

    /**
     * @brief Set the scene for the protagonist's view.
     * @param newScene The new scene.
     */
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);
 
    /**
     * @brief Set the protagonist's model.
     * @param newProtModel The new protagonist model.
     */
    void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) override;

//clear
    /**
     * @brief Clear the protagonist's view.
     */
    void clearView() override;

private:
    std::shared_ptr<QGraphicsPixmapItem> protagonistDisplay; 
    int tileDim {50};

    std::shared_ptr<HealthProgressBar> healthBar;
    std::shared_ptr<EnergyProgressBar> energyBar;
    std::shared_ptr<QGraphicsScene> scene;
    QPixmap prot;
};

#endif // PROTAGONISTVIEWGRAPHICAL_H
