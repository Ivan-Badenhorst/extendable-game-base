#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "world.h"


/**
 * @class ProtagonistModel
 * @brief A model class for the protagonist in the game.
 *
 * This class is responsible for managing the protagonist's state and behavior.
 * It inherits from the World class where it gets a protagonist.
 */
class ProtagonistModel: public World
{
public:
    /**
     * @brief Constructor that initializes the protagonist model, extracting info from the unique protagonist.
     * @param prot Unique pointer to a Protagonist object.
     */
    ProtagonistModel(std::unique_ptr<Protagonist> prot);

//position-related methods
    
    /**
     * @brief Get the protagonist's current X position.
     * @return The protagonist's current X position.
     */
    int getPositionX() const;
    
    /**
     * @brief Get the protagonist's current Y position.
     * @return The protagonist's current Y position.
     */
    int getPositionY() const;

    /**
     * @brief Update the protagonist's position.
     * @param newXPos The new X position.
     * @param newYPos The new Y position.
     */
    void updatePosition(int newXPos, int newYPos);

    /**
     * @brief Check if the protagonist is in the danger zone.
     * @return True if the protagonist is in the danger zone, false otherwise.
     */
    bool getInDangerZone() const;

    /**
     * @brief Set the protagonist's danger zone status.
     * @param newInDangerZone The new danger zone status.
     */
    void setInDangerZone(bool newInDangerZone);



//health-related methods

    /**
     * @brief Get the protagonist's current health.
     * @return The protagonist's current health.
     */
    float getCurrentHealth() const;
    
     /**
     * @brief Get the protagonist's maximum health.
     * @return The protagonist's maximum health.
     */   
    float getMaxhealth() const;

     /**
     * @brief Set the protagonist's maximum health.
     * @param value The new maximum health value.
     */   
    void setMaxHealth(float value);

    /**
     * @brief Update the protagonist's health and if applicable, also the maxHealth.
     * @param hpValue The amount to update the health by
     * @return True if current health is less than or equal to 0, false otherwise.
     */
    bool updateHealth(float hpValue);  

    /**
     * @brief Decrease the protagonist's current health.
     * @param hpValue The amount to decrease the current health by.
     */
    void takeDamage(int hpValue);

    /**
     * @brief Get the protagonist's attack damage.
     * @return The protagonist's attack damage.
     */
    int getAttackDamage() const;

    /**
     * @brief Set the protagonist's attack damage.
     * @param newAttackDamage The new attack damage.
     */
    void setAttackDamage(int newAttackDamage);


//energy-related methods

     /**
     * @brief Get the protagonist's current energy.
     * @return The protagonist's current energy.
     */   
    float getEnergy() const;

     /**
     * @brief Update the protagonist's energy.
     * @param value The new energy value.
     * @return True if energy is less than or equal to 0, false otherwise.
     */   
    bool updateEnergy(float energy);

    /**
     * @brief Get the protagonist's maximum energy.
     * @return The protagonist's maximum energy.
     */
    float getMaxEnergy() const;

// Add more methods as and when needed

private:
    int xPos {0};
    int yPos {0};
    float maxHealth {0.0f};
    float currentHealth{0.0f};
    float energy {0.0f};
    int attackDamage {10};
    float maxEnergy{0.0f};
    bool inDangerZone{false};
};

#endif // PROTAGONISTMODEL_H
