#include "tilemodel.h"
#include <vector>

TileModel::TileModel()
{

}

void TileModel::populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile> > tile)
{
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
