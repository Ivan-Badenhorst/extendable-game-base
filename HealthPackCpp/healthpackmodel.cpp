#include "HealthPackH/healthpackmodel.h"

#include <iostream>

HealthPackModel::HealthPackModel(std::vector<std::unique_ptr<Tile> > tiles)
{
    for(auto& t:tiles){
        std::array<int, 3> hp;
        hp[1] = t->getYPos();
        hp[0] = t->getXPos();
        hp[2] = 1;
        std::cout << hp[1] << ";" << hp[0] << std::endl;
        healthPacks.push_back(hp);
    }
}

std::vector<std::array<int, 3> > HealthPackModel::getHealthPacks() const
{
    return healthPacks;
}

bool HealthPackModel::containsHp(int row, int col)
{
    for(auto& hp: healthPacks){
        if(hp[0] == row && hp[1] == col && hp[2] > 0){
            hp[2] = 0;
            return true;
        }
    }
    return false;
}
