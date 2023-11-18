#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "world.h"


struct ProtagonistData {
    int x;
    int y;
    float health;
    float energy;
};

class ProtagonistModel: public World
{
public:
    ProtagonistModel(std::unique_ptr<Protagonist> prot);
    ProtagonistData getProtagonistData() const;
    // Methods to interact with the stored protagonist data
    int getPositionX() const { return protagonistData.x; }
    int getPositionY() const { return protagonistData.y; }
    float getHealth() const { return protagonistData.health; }
    void setHealth(float value) { protagonistData.health = value; }
    float getEnergy() const { return protagonistData.energy; }
    void setEnergy(float value) { protagonistData.energy = value; }
    // Add more methods as and when needed (also question. should i make them all inline?)
private:
    ProtagonistData protagonistData; // Struct to store protagonist data
};

#endif // PROTAGONISTMODEL_H
