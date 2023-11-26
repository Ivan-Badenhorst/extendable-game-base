#ifndef HEALTHPACKMODEL_H
#define HEALTHPACKMODEL_H

#include "world.h"
#include <vector>

class HealthPackModel
{
public:
    HealthPackModel(std::vector<std::unique_ptr<Tile>> tiles);
    std::vector<std::array<int, 3> > getHealthPacks() const;
    bool containsHp(int row, int col);

private:
    std::vector<std::array<int, 3>> healthPacks;// [x, y, value]
};

#endif // HEALTHPACKMODEL_H
