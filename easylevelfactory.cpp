#include "easylevelfactory.h"


EasyLevelFactory::EasyLevelFactory()
{

}

Level* EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 0,0);
    TileModel tm;
    tm.populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    TileView tv(mw, std::make_shared<TileModel>(tm));

    TileController tc(std::make_shared<TileView>(tv), std::make_shared<TileModel>(tm));


    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc));

    return easyLevel;




}

