#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "world.h"


//struct ProtagonistData {
//    int x;
//    int y;
//    float health;
//    float energy;
//};

class ProtagonistModel: public World
{
public:
    ProtagonistModel(std::unique_ptr<Protagonist> prot);


    int getPositionX() const;
    int getPositionY() const;
    float getCurrentHealth() const;
    float getMaxhealth() const;
    void setMaxHealth(float value);
    float getEnergy() const;
    void setEnergy(float value);
    // Add more methods as and when needed

    void addHealth(int hpValue);

    // add a method that moves the protagonist later
    const std::unique_ptr<Protagonist>& getProtagonist()const;

private:
//    std::unique_ptr<Protagonist> protagonist; // Unique pointer to hold the Protagonist
    int xPos {0};
    int yPos {0};
    float maxHealth {0.0f};
    float currentHealth{0.0f};
    float energy {0.0f};
};

#endif // PROTAGONISTMODEL_H
