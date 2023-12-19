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

void TileModel::addPortal(int row, int col, bool nextLevel)
{
    Portal p;
    p.row = row;
    p.col = col;
    p.nextLevel = nextLevel;
    if(nextLevel) portals.second = p;
    else portals.first = p;
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

std::optional<bool> TileModel::getPortalAt(int row, int col)
{
    std::optional<bool> b;

    auto portal = portals.first;
    if (portal.row == row && portal.col == col) {
        b.reset();
        b = portal.nextLevel;
        return b;  // Found the portal
    }

    portal = portals.second;
    if (portal.row == row && portal.col == col) {
        b.reset();
        b = portal.nextLevel;
        return b;  // Found the portal
    }

    return b;  // No portal found
}

std::pair<Portal, Portal> TileModel::getPortals() const
{
    return portals;
}
