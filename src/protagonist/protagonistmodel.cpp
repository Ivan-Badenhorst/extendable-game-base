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

int ProtagonistModel::getPositionX() const
{
    return xPos;
}

int ProtagonistModel::getPositionY() const
{
    return yPos;
}

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

void ProtagonistModel::updatePosition(int newXPos, int newYPos)
{
    xPos = newXPos;
    yPos = newYPos;
}


void ProtagonistModel::addHealth(int hpValue)
{
    maxHealth += hpValue;
    currentHealth = maxHealth;
}

void ProtagonistModel::takeDamage(int hpValue)
{
    currentHealth -= hpValue;
}

bool ProtagonistModel::updateHealth(float hpValue)
{
    currentHealth += hpValue;
    if(currentHealth > maxHealth){
        maxHealth = currentHealth;
    }
    return (currentHealth <= 0);
}

int ProtagonistModel::getAttackDamage() const
{
    return attackDamage;
}

void ProtagonistModel::setAttackDamage(int newAttackDamage)
{
    attackDamage = newAttackDamage;
}



