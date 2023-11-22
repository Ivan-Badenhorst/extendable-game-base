#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
    : protagonist(std::move(prot))
{
//    protagonistData.x = prot->getXPos();
//    protagonistData.y = prot->getYPos();
//    protagonistData.health = prot->getHealth();
    //    protagonistData.energy = prot->getEnergy();
}

//std::unique_ptr<Protagonist> ProtagonistModel::getProtagonist() const
//{
//    return protagonist;
//}



//ProtagonistData ProtagonistModel::getProtagonistData() const
//{
//    return protagonistData;
//}


