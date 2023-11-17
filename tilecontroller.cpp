#include "tilecontroller.h"

TileController::TileController(std::shared_ptr<TileViewGraphical> tv, std::shared_ptr<TileModel> tm)
      :tileView(tv), tileModel(tm)
{

}

void TileController::update()
{
    tileView->update();
}


