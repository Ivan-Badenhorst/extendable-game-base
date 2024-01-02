#include "tilemodel.h"
#include <vector>

#include <iostream>
#include <optional>

#include <functional>
TileModel::TileModel(int rows, int cols)
{
    columns = cols;
    Tile startTile(0,0,0);
    Tile destinationTile(0,0,0);

    comp = [this](const Node& a, const Node& b) { return this->compareNodes(a,b); };
    finder = nullptr; //std::make_unique<PathFinder<Node, Tile>>(nodes, &startTile, &destinationTile, comp, columns, 0);

//    finder = PathFinder<Node, Tile>& pf(nodes, &startTile, &destinationTile, comp, columns, 0);
}

void TileModel::populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile> > tile)
{
    this->rows = rows;
    columns = cols;
    tileTable.reserve(rows);
    visitedTiles.assign(rows, std::vector<bool>(cols, false));


    for (int i = 0; i < rows; i++) {
        tileTable.emplace_back();
        tileTable.back().reserve(cols);
    }

    for(int j = 0; j < tile.size(); j++){

        tileTable[j/cols].push_back(tile[j]->getValue());
        //convert tiles to nodes and place them in the node 1D list
        nodes.push_back(Node(tile[j]->getXPos(),tile[j]->getYPos(),tile[j]->getValue()));

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


float TileModel::getTileValueAt(int row, int col)
{
    if(row>=0 && row<rows && col>=0 && col<columns){
        return tileTable[row][col];
    }
    return 0.0f;
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


void TileModel::markTileAsVisited(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        visitedTiles[row][col] = true;
    }
}

bool TileModel::isTileVisited(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        return visitedTiles[row][col];
    }
    return false;
}

std::vector<int> TileModel::findPath(int startX, int startY, int endX, int endY)
{
    Tile startTile(startX, startY,  getTileValueAt(startX, startY) );
    Tile destinationTile(endX, endY, getTileValueAt(endX, endY));

    getPathfinder(startTile, destinationTile);
    std::cout << "Pathfinder created" << std::endl;
    std::vector<int> moveList = finder->A_star();
    std::cout << "Pathfinder finished" << std::endl;
    return moveList;
}

bool TileModel::compareNodes(const Node& a, const Node& b) {
    return a.getValue() > b.getValue();  // or any other comparison logic relevant to your application
}

void TileModel::getPathfinder(Tile& startTile, Tile& destinationTile)
{
    for (auto& node : nodes) {
        node.visited = false; // Reset all nodes' visited status to false
        node.f =0;
        node.g = 0;
        node.h =0;
        node.prev = nullptr;
    }
    finder.release();

    finder = std::make_unique<PathFinder<Node, Tile>>(nodes, &startTile, &destinationTile, comp, columns, std::numeric_limits<float>::infinity());

}

