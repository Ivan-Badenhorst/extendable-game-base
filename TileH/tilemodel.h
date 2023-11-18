#ifndef TILEMODEL_H
#define TILEMODEL_H
#include "world.h"

class TileModel
{
public:
    TileModel();
    void populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile>> tile);

    std::vector<std::vector<float> > getTileTable() const;

    int getRows() const;

    int getColumns() const;

private:
    std::vector<std::vector<float>> tileTable;
    int rows;
    int columns;

};

#endif // TILEMODEL_H
