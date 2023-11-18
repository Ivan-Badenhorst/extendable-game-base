#include "protagonistmodel.h"

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
{
    protagonistData.x = prot->getXPos();
    protagonistData.y = prot->getYPos();
    protagonistData.health = prot->getHealth();
    protagonistData.energy = prot->getEnergy();
}

ProtagonistData ProtagonistModel::getProtagonistData() const
{
    return protagonistData;
}


