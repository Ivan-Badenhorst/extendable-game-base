#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
{
    xPos = prot->getXPos();
    yPos = prot->getYPos();
    maxHealth = prot->getHealth();
    currentHealth = maxHealth;
    maxEnergy = prot->getEnergy();
    energy = maxEnergy;
}


//position-related methods
int ProtagonistModel::getPositionX() const
{
    return xPos;
}

int ProtagonistModel::getPositionY() const
{
    return yPos;
}

void ProtagonistModel::updatePosition(int newXPos, int newYPos)
{
    xPos = newXPos;
    yPos = newYPos;
}

bool ProtagonistModel::getInDangerZone() const
{
    return inDangerZone;
}

void ProtagonistModel::setInDangerZone(bool newInDangerZone)
{
    inDangerZone = newInDangerZone;
}


//health-related methods

float ProtagonistModel::getCurrentHealth() const
{
    return currentHealth;
}

float ProtagonistModel::getMaxhealth() const
{
    return maxHealth;
}

void ProtagonistModel::setMaxHealth(float value)
{
    maxHealth = value;
}

bool ProtagonistModel::updateHealth(float hpValue)
{
    currentHealth += hpValue;
    if(currentHealth > maxHealth){
        maxHealth = currentHealth;
    }
    return (currentHealth <= 0);
}

void ProtagonistModel::takeDamage(int hpValue)
{
    currentHealth -= hpValue;
}

int ProtagonistModel::getAttackDamage() const
{
    return attackDamage;
}

void ProtagonistModel::setAttackDamage(int newAttackDamage)
{
    attackDamage = newAttackDamage;
}

//energy-related methods

float ProtagonistModel::getEnergy() const
{
    return energy;
}

bool ProtagonistModel::updateEnergy(float value)
{
    energy += value;
    return (energy <= 0);
}

float ProtagonistModel::getMaxEnergy() const
{
    return maxEnergy;
}
