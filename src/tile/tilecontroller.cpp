#include "tilecontroller.h"
#include "gamecontroller.h"

TileController::TileController(std::shared_ptr<TileModel> tm)
      :tileModel(tm)
{

}


float TileController::update(int row, int col, bool allowPortal)
{
    auto p = tileModel->getPortalAt(row, col);
    tileModel->markTileAsVisited(row,col);
    if(p.has_value() && allowPortal){
        auto gc = GameController::getInstance();
        if(p.value()) {gc->nextLevel();}
        else{ gc->previousLevel();}
    }
    else{
        tileView->update(row, col);
    }
    float val = tileModel->getTileValueAt(row,col);
    return val;
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

float TileController::getEnergy(int row, int col)
{
    return tileModel->getTileValueAt(row, col);
}

std::shared_ptr<TileModel> TileController::getTileModel() const
{
    return tileModel;
}


