#include "TileH/tilecontroller.h"
#include "gamecontroller.h"

TileController::TileController(std::shared_ptr<TileModel> tm)
      :tileModel(tm)
{

}

void TileController::update(int row, int col)
{
    auto p = tileModel->getPortalAt(row, col);
    if(p.has_value()){
        auto gc = GameController::getInstance();
        if(p.value()){
            //next level
        }
        else{
            //previous level
        }
    }
    tileView->update(row, col);
}

std::tuple<int, int> TileController::getDimensions()
{

    return std::make_tuple(tileModel->getRows(), tileModel->getColumns()); // Return a tuple of ints

}

void TileController::addPortal(int row, int col, bool nextLevel)
{
    tileModel->addPortal(row, col, nextLevel);
}

void TileController::setTileView(const std::shared_ptr<TileView> &newTileView)
{
    tileView = newTileView;

}

std::shared_ptr<TileModel> TileController::getTileModel() const
{
    return tileModel;
}


