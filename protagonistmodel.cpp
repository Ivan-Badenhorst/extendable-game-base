#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
{
    xPos = prot->getXPos();
    yPos = prot->getYPos();
    health = prot->getHealth();
    energy = prot->getEnergy();
}

int ProtagonistModel::getPositionX() const
{
    return xPos;
}

int ProtagonistModel::getPositionY() const
{
    return yPos;
}

float ProtagonistModel::getHealth() const
{
    return health;
}

void ProtagonistModel::setHealth(float value)
{
    health = value;
}

float ProtagonistModel::getEnergy() const
{
    return energy;
}

void ProtagonistModel::setEnergy(float value)
{
    energy = value;
}



