#include "HealthPackH/healthpackmodel.h"


HealthPackModel::HealthPackModel(std::vector<std::unique_ptr<Tile> > tiles)
{
    for(auto& t:tiles){
        std::array<int, 3> hp;
        hp[0] = t->getXPos();
        hp[1] = t->getYPos();
        hp[2] = 1;
        healthPacks.push_back(hp);
    }
}

std::vector<std::array<int, 3> > HealthPackModel::getHealthPacks() const
{
    return healthPacks;
}
