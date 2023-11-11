#ifndef TILEMODEL_H
#define TILEMODEL_H
#include "world.h"

class TileModel
{
public:
    TileModel();
    void populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile>> tile);

    std::vector<std::vector<float> > getTileTable() const;

private:
    std::vector<std::vector<float>> tileTable;

};

#endif // TILEMODEL_H
