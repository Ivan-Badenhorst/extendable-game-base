#include "tilecontroller.h"

TileController::TileController(TileView &tv, TileModel &tm)
      :tileView(tv), tileModel(tm)
{

}

void TileController::update()
{
    tileView.update();
}
