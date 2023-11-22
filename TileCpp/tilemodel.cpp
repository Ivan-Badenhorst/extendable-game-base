#include "TileH/tilemodel.h"
#include <vector>

#include <iostream>

TileModel::TileModel()
{

}

void TileModel::populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile> > tile)
{
    this->rows = rows;
    columns = cols;
    tileTable.reserve(rows);


    for (int i = 0; i < rows; i++) {
        tileTable.emplace_back();
        tileTable.back().reserve(cols);
    }

    for(int j = 0; j < tile.size(); j++){

        tileTable[j/cols].push_back(tile[j]->getValue());
    }
}

std::vector<std::vector<float> > TileModel::getTileTable() const
{
    return tileTable;
}

int TileModel::getRows() const
{
    return rows;
}

int TileModel::getColumns() const
{
    return columns;
}
