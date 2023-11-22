#include "TileH/tilecontroller.h"

TileController::TileController(std::shared_ptr<TileView> tv, std::shared_ptr<TileModel> tm)
      :tileView(tv), tileModel(tm)
{

}

void TileController::update(int row, int col)
{
    tileView->update(row, col);
}

std::tuple<int, int> TileController::getDimensions()
{

    return std::make_tuple(tileModel->getRows(), tileModel->getColumns()); // Return a tuple of ints

}


