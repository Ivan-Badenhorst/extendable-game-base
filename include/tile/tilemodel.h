#ifndef TILEMODEL_H
#define TILEMODEL_H
#include "world.h"
#include "node.h"


///TODO:
/// ADAPT SUCH THAT YOU CAN ADJUST HP VALUE IF ITS BEEN USED
/// ADAPT SUCH THAT YOU CAN GIVE A POSITION AND IT CHECKS IF SOMETHING NEEDS TO BE ADJUSTED
///     IF YES -> RETURN TRUE SO THAT CONTROLLER KNOWS TO CALL VISUALIZATION
///     IF YES -> SIGNAL PROTAGONIST CONTROLER SO THAT WE UPDATE HIS MODEL
struct Portal {
    int row=-1;
    int col=-1;
    bool nextLevel;
};



class TileModel
{
public:
    TileModel();
    void populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile>> tile);

    void addPortal(int row, int col, bool nextLevel);

    std::vector<std::vector<float> > getTileTable() const;
    int getRows() const;
    int getColumns() const;
    float getTileValueAt(int row, int col);
    std::optional<bool> getPortalAt(int row, int col);
    std::pair<Portal, Portal> getPortals() const;
    void markTileAsVisited(int row, int col);
    bool isTileVisited(int row, int col) const;
    std::vector<int> findPath(int startX, int startY, int endX, int endY);
    bool compareNodes(const Node& a, const Node& b);


private:
    std::vector<std::vector<float>> tileTable;
    std::vector<std::vector<bool>> visitedTiles;
    int rows;
    int columns;
    std::pair<Portal, Portal> portals;
    std::vector<Node> nodes;


};

#endif // TILEMODEL_H
