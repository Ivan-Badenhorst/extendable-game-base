#include "gamecontroller.h"
#include "HealthPackH/healthpackviewgraphical.h"
#include "enemyviewgraphical.h"
#include "penemymodel.h"
#include "penemyviewgraphical.h"
#include "protagonistviewgraphical.h"

#include <iostream>
#include <memory>

#include <thread>
#include <chrono>
#include <QCoreApplication>
#include <QEventLoop>


GameController*  GameController::gameControllerInstance = nullptr;


GameController::GameController()
{

}

void GameController::input(const ArrowDirection &direction)
{
    switch (direction) {
    case ArrowDirection::Left:
        if(col > 0) col--;
        break;
    case ArrowDirection::Right:
        if(col < width-1) col++;
        break;
    case ArrowDirection::Up:
        if(row > 0) row--;
        break;
    case ArrowDirection::Down:
        if(row < height-1) row++;
        break;
    }

    int hpVal = hpController->update(row, col);
    if(hpVal > 0){
        protController->addHealth(hpVal);
    }
    protController->update(row, col);
    tileController->update(row, col);


}



GameController* GameController::getInstance()
{
    if (gameControllerInstance == nullptr)
    {
        gameControllerInstance = new GameController();
    }
    return gameControllerInstance;

}
void GameController::startGame(MainWindow & mw, std::unique_ptr<GameView> gv)
{
    gameView = std::move(gv);

    EasyLevelFactory easyLevelFactory;
    auto level = easyLevelFactory.createWorld(mw);
    EasyLevel* easyLevel = static_cast<EasyLevel*>(level);

    tileController = easyLevel->getTileController();

    auto [h, w] = tileController->getDimensions();
    height = h;
    width = w;


    hpController = easyLevel->getHpController();
    protController = easyLevel->getProtController();
    enemyController = easyLevel->getEnemyController();

    //setup graphic views:
    auto tv = std::make_shared<TileViewGraphical>(tileController->getTileModel());
    gameView->setTileView(tv);
    auto hpv = std::make_shared<HealthPackViewGraphical>(hpController->getHpModel());
    gameView->setHpView(hpv);
    auto pv = std::make_shared<ProtagonistViewGraphical>(protController->getProtModel());
    gameView->setProtView(pv);
    auto em = enemyController->getEnemyModels();
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews;
    //IF WE GET MORE TYPE OF ENEMIES WE HAVE TO GO THROUGH THIS IN A BETTER WAY!!!!
    for(auto& e: em){
        if (auto pEnemyModel = dynamic_cast<PEnemyModel*>(e.get())) {
            std::shared_ptr<EnemyViewInterface> pev = std::make_shared<PEnemyViewGraphical>(std::make_shared<PEnemyModel>(*pEnemyModel));
            enemyViews.push_back(pev);
        } else if(auto enemyModel = dynamic_cast<EnemyModel*>(e.get())){
            std::shared_ptr<EnemyViewInterface> ev = std::make_shared<EnemyViewGraphical>(std::make_shared<EnemyModel>(*enemyModel));
            enemyViews.push_back(ev);
        }
    }
    gameView->setEnemyView(enemyViews);

    initializeView();

    tileController->update(0, 0);
    hpController->refreshAll();
    protController->refreshAll();
    enemyController->refreshAllGraphical();
    

}

void GameController::initializeView()
{
    gameView->initializeMainWindow();
    tileController->setTileView(gameView->getTileView());
    protController->setProtView(gameView->getProtView());
    enemyController->setEnemyView(gameView->getEnemyView());
    hpController->setHpView(gameView->getHpView());

}

void GameController::setNewView(std::unique_ptr<GameView> gv)
{
//    gameView->clearMainWindow();
    gameView = std::move(gv);
    initializeView();
}





