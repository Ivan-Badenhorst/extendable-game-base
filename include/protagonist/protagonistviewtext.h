#ifndef PROTAGONISTVIEWTEXT_H
#define PROTAGONISTVIEWTEXT_H


#include "protagonistmodel.h"
#include "protagonistview.h"
#include "qlabel.h"
#include "qplaintextedit.h"
#include <memory>

/**
 * @class ProtagonistViewText
 * @brief A text-based view for the protagonist in the game.
 *
 * This class is responsible for updating and animating the protagonist's text-based view.
 * It uses a shared pointer to a ProtagonistModel object to get the protagonist's state.
 * It implements the ProtagonistView interface.
 */
class ProtagonistViewText: public ProtagonistView
{
public:
    /**
     * @brief Default constructor.
     */
    ProtagonistViewText();
    
    /**
     * @brief Generic refresh of the protagonist's view. 
     * Implicitly updates protagonist view based on current position of protagonist from model.
     * Also updates health and energy labels.
     */
    void update() override;

    /**
     * @brief Update the protagonist's text view given position.
     * 
     * Erases the previous position and updates textual representation of protagonist in the new position.
     * Internally calls erasePreviousPosition() 
     * @param row The row position.
     * @param col The column position.
     */    
    void update(int row, int col) override;

    /**
     * @brief Update the protagonist's health label view.
     */
    void updateHealth() override;
    
    /**
     * @brief Update the protagonist's energy label view.
     */
    void updateEnergy() override;

    //animation methods

    /**
     * @brief Perform the protagonist's attack animation.
     * custom implementation can be provided if needed
     * @param currentFrame The current frame of the animation.
     */
    void performAttack(int currentFrame) override;

    /**
     * @brief Perform the protagonist's health gain animation.
     * custom implementation can be provided if needed
     * @param currentFrame The current frame of the animation.
     */
    void performHealthGain(int currentFrame) override;

    /**
     * @brief Perform the protagonist's death animation.
     * custom implementation can be provided if needed
     * @param currentFrame The current frame of the animation.
     */
    void performDeath(int currentFrame) override;

    /**
     * @brief Perform the protagonist's take damage animation.
     * custom implementation can be provided if needed
     * @param currentFrame The current frame of the animation.
     */
    void performTakeDamage(int currentFrame) override;

    /**
     * @brief Set the protagonist's model.
     * @param newProtModel The new protagonist model.
     */
    void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) override;

    /**
     * @brief Set the text edit for the protagonist's view.
     * @param newTextEdit The new text edit.
     */    
    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

    /**
     * @brief Set the health label for the protagonist's view.
     * @param healthValue The new health label.
     */
    void setHealthLabels(std::shared_ptr<QLabel> healthValue);

    /**
     * @brief Set the energy label for the protagonist's view.
     * @param energyValue The new energy label.
     */
    void setEnergyLabels(std::shared_ptr<QLabel> energyValue);
    
    /**
     * @brief Clear the protagonist's view.
     */
    void clearView() override;


private:
    /**
     * @brief Erase the protagonist's previous position in the text view.
     */
    void erasePreviousPosition();


    std::shared_ptr<ProtagonistModel> protModel;
    std::shared_ptr<QPlainTextEdit> textEdit;
    std::shared_ptr<QLabel> healthValueLabel;
    std::shared_ptr<QLabel> energyValueLabel;

};

#endif // PROTAGONISTVIEWTEXT_H
