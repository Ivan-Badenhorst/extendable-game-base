#include "tilecontroller.h"

TileController::TileController(std::shared_ptr<TileView> tv, std::shared_ptr<TileModel> tm)
      :tileView(tv), tileModel(tm)
{

}

void TileController::update(int row, int col)
{
    tileView->update(row, col);
}


