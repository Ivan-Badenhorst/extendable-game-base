#include "easylevelfactory.h"


EasyLevelFactory::EasyLevelFactory()
{

}

Level EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 0,0);
    TileModel tm;
    tm.populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    TileView tv(mw, tm);

    TileController tc(tv, tm);


    EasyLevel el(std::make_shared<TileController>(tc));

    return el;




}

