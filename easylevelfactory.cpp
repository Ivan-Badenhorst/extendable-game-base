#include "easylevelfactory.h"


EasyLevelFactory::EasyLevelFactory()
{

}

Level EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 0,0);
    auto tm = new TileModel();
    tm->populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    auto tv = new TileView(mw, std::make_shared<TileModel>(tm));

    auto tc = new TileController(std::make_shared<TileView>(tv), std::make_shared<TileModel>(tm));


    EasyLevel easyLevel(std::make_shared<TileController>(tc));

    return easyLevel;




}

