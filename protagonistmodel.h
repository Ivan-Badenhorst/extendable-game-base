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
//    ProtagonistModel() = default;
    // Methods to interact with the stored protagonist data
//     ProtagonistData getProtagonistData() const;
//    int getPositionX() const { return protagonistData.x; }
//    int getPositionY() const { return protagonistData.y; }
//    float getHealth() const { return protagonistData.health; }
//    void setHealth(float value) { protagonistData.health = value; }
//    float getEnergy() const { return protagonistData.energy; }
//    void setEnergy(float value) { protagonistData.energy = value; }

    int getPositionX() const { return protagonist->getXPos(); }
    int getPositionY() const { return protagonist->getYPos(); }
    float getHealth() const { return protagonist->getHealth(); }
    void setHealth(float value) { protagonist->setHealth(value); }
    float getEnergy() const { return protagonist->getEnergy(); }
    void setEnergy(float value) { protagonist->setEnergy(value); }
    // Add more methods as and when needed (also question. should i make them all inline?)

    // add a method that moves it

//    std::shared_ptr<Protagonist> getProtagonist() const;

private:
//    ProtagonistData protagonistData; // Struct to store protagonist data
    std::unique_ptr<Protagonist> protagonist; // Unique pointer to hold the Protagonist
};

#endif // PROTAGONISTMODEL_H
