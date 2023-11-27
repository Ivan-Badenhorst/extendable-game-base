#include "HealthPackH/healthpackmodel.h"

#include <iostream>

HealthPackModel::HealthPackModel(std::vector<std::unique_ptr<Tile> > tiles, int hpValue)
{
    for(auto& t:tiles){
        std::array<int, 3> hp;
        hp[1] = t->getYPos();
        hp[0] = t->getXPos();
        hp[2] = hpValue;
        healthPacks.push_back(hp);
    }
}

std::vector<std::array<int, 3> > HealthPackModel::getHealthPacks() const
{
    return healthPacks;
}

int HealthPackModel::containsHp(int row, int col)
{
    for(auto& hp: healthPacks){
        if(hp[0] == row && hp[1] == col && hp[2] > 0){
            int val = hp[2];
            hp[2] = 0;
            std::cout << "in model val we ret is: " << val << std::endl;
            return val;
        }
    }
    return 0;
}
