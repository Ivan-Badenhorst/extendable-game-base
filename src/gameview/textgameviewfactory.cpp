#include "textgameviewfactory.h"
#include "enemyviewtext.h"
#include "healthpackviewtext.h"
#include "penemyviewtext.h"
#include "protagonistviewtext.h"
#include "textgameview.h"
#include "tileviewtext.h"

#include <memory>

TextGameViewFactory::TextGameViewFactory()
{

}

std::unique_ptr<GameView> TextGameViewFactory::createView(MainWindow& mainWindow)
{
    auto gameView = std::make_unique<TextGameView>(mainWindow);

    //make the views:
    gameView->setHpView(std::make_shared<HealthPackViewText>());
    gameView->setProtView(std::make_shared<ProtagonistViewText>());
    gameView->setTileView(std::make_shared<TileViewText>());

    //for each type of enemy view we make a view!
    std::vector<std::shared_ptr<BaseEnemyView>> enemyViews;
    auto pev = std::make_shared<PEnemyViewText>();
    enemyViews.push_back(pev);
    auto ev = std::make_shared<EnemyViewText>();
    enemyViews.push_back(ev);
    gameView->setEnemyView(enemyViews);

    return gameView;
}
