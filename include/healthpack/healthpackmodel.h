#ifndef HEALTHPACKMODEL_H
#define HEALTHPACKMODEL_H

#include "world.h"
#include <vector>

class HealthPackModel
{
public:
    HealthPackModel(std::vector<std::unique_ptr<Tile>> tiles, int hpValue);
    std::vector<std::array<int, 3> > getHealthPacks() const;
    int containsHp(int row, int col);

private:
    std::vector<std::array<int, 3>> healthPacks;// [x, y, value]
};

#endif // HEALTHPACKMODEL_H
