#include "TileH/tilecontroller.h"

TileController::TileController(std::shared_ptr<TileModel> tm)
      :tileModel(tm)
{

}

float TileController::update(int row, int col)
{
    tileView->update(row, col);
    float val = tileModel->getTileValueAt(row,col);
    return val;
}

std::tuple<int, int> TileController::getDimensions()
{

    return std::make_tuple(tileModel->getRows(), tileModel->getColumns()); // Return a tuple of ints

}

void TileController::setTileView(const std::shared_ptr<TileView> &newTileView)
{
    tileView = newTileView;

}

std::shared_ptr<TileModel> TileController::getTileModel() const
{
    return tileModel;
}


