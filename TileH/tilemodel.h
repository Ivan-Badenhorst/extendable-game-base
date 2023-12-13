#ifndef TILEMODEL_H
#define TILEMODEL_H
#include "world.h"

///TODO:
/// ADAPT SUCH THAT YOU CAN ADJUST HP VALUE IF ITS BEEN USED
/// ADAPT SUCH THAT YOU CAN GIVE A POSITION AND IT CHECKS IF SOMETHING NEEDS TO BE ADJUSTED
///     IF YES -> RETURN TRUE SO THAT CONTROLLER KNOWS TO CALL VISUALIZATION
///     IF YES -> SIGNAL PROTAGONIST CONTROLER SO THAT WE UPDATE HIS MODEL

class TileModel
{
public:
    TileModel();
    void populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile>> tile);

    std::vector<std::vector<float> > getTileTable() const;

    int getRows() const;

    int getColumns() const;
    float getTileValueAt(int row, int col);

private:
    std::vector<std::vector<float>> tileTable;
    int rows;
    int columns;

};

#endif // TILEMODEL_H
