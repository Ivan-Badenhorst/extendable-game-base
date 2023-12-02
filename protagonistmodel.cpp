#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
{
    xPos = prot->getXPos();
    yPos = prot->getYPos();
    maxHealth = prot->getHealth();
    currentHealth = maxHealth;
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

void ProtagonistModel::setEnergy(float value)
{
    energy = value;
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

int ProtagonistModel::getAttackDamage() const
{
    return attackDamage;
}

void ProtagonistModel::setAttackDamage(int newAttackDamage)
{
    attackDamage = newAttackDamage;
}




