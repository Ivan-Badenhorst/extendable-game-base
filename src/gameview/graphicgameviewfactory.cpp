#include "graphicgameviewfactory.h"
#include "healthpackviewgraphical.h"
#include "tileviewgraphical.h"
#include "enemyviewgraphical.h"
#include "penemyviewgraphical.h"
#include "protagonistviewgraphical.h"
#include "graphicalgameview.h"

#include <memory>


GraphicGameViewFactory::GraphicGameViewFactory()
{

}

std::unique_ptr<GameView> GraphicGameViewFactory::createView(MainWindow &mainWindow)
{
    auto gameView = std::make_unique<GraphicalGameView>(mainWindow);

    //make the views:
    gameView->setHpView(std::make_shared<HealthPackViewGraphical>());
    gameView->setProtView(std::make_shared<ProtagonistViewGraphical>());
    gameView->setTileView(std::make_shared<TileViewGraphical>());

    //for each type of enemy view we make a view!
    std::vector<std::shared_ptr<BaseEnemyView>> enemyViews;
    auto pev = std::make_shared<PEnemyViewGraphical>();
    enemyViews.push_back(pev);
    auto ev = std::make_shared<EnemyViewGraphical>();
    enemyViews.push_back(ev);
    gameView->setEnemyView(enemyViews);

    return gameView;

}
