#include "easylevelfactory.h"
#include "tilemodel.h"
#include "tileviewgraphical.h"
#include "tilecontroller.h"
#include "protagonistcontroller.h"
#include "protagonistmodel.h"
#include "protagonistviewgraphical.h"
#include "easylevel.h"

EasyLevelFactory::EasyLevelFactory()
{

}

Level* EasyLevelFactory::createWorld(MainWindow& mw)
{
    World w;
    w.createWorld(":/worldmap.png", 0,0);

    TileModel tm;
    tm.populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    
    TileViewGraphical tv(mw, std::make_shared<TileModel>(tm));
    
    TileController tc(std::make_shared<TileViewGraphical>(tv), std::make_shared<TileModel>(tm));

    //protagonist:
    std::unique_ptr<Protagonist> protagonistPtr = w.getProtagonist();
    auto pm = std::make_shared<ProtagonistModel>(std::move(protagonistPtr));
    auto pvg = std::make_shared<ProtagonistViewGraphical>(mw, pm);
    ProtagonistController pc(pvg,pm);


    auto easyLevel = new EasyLevel(std::make_shared<TileController>(tc), std::make_shared<ProtagonistController>(pc));

    return easyLevel;
}

