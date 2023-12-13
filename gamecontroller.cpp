#include "gamecontroller.h"
#include "HealthPackH/healthpackviewgraphical.h"
#include "enemyviewgraphical.h"
#include "enemyviewtext.h"
#include "penemymodel.h"
#include "penemyviewgraphical.h"
#include "penemyviewtext.h"
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
    auto prevRow = row;
    auto prevCol = col;

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
    enemyController->refreshAllGraphical();
    float tileVal=tileController->update(row, col);
    if (tileVal > 0) protController->updateEnergy(tileVal);
    int hpVal = hpController->update(row, col);
    if (hpVal > 0)   protController->addHealth(hpVal);
    protController->update(row, col);
    //tileController->update(row, col);
    hpController->update(prevRow, prevCol);


}



GameController* GameController::getInstance()
{
    if (gameControllerInstance == nullptr)
    {
        gameControllerInstance = new GameController();
    }
    return gameControllerInstance;

}
void GameController::startGame(std::unique_ptr<GameView> gv)
{
    gameView = std::move(gv);

    EasyLevelFactory easyLevelFactory;
    auto level = easyLevelFactory.createWorld();
    EasyLevel* easyLevel = static_cast<EasyLevel*>(level);

    tileController = easyLevel->getTileController();

    auto [h, w] = tileController->getDimensions();
    height = h;
    width = w;


    hpController = easyLevel->getHpController();
    protController = easyLevel->getProtController();
    enemyController = easyLevel->getEnemyController();

    //setup graphic views:
    auto tv = std::make_shared<TileViewGraphical>();
    tv->setTileModel(tileController->getTileModel());
    gameView->setTileView(tv);
    auto hpv = std::make_shared<HealthPackViewGraphical>();
    hpv->setHpModel(hpController->getHpModel());
    gameView->setHpView(hpv);
    auto pv = std::make_shared<ProtagonistViewGraphical>();
    pv->setProtModel(protController->getProtModel());
    gameView->setProtView(pv);
    auto em = enemyController->getAllEnemyModels();
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews;

    //IF WE GET MORE TYPE OF ENEMIES WE HAVE TO GO THROUGH THIS IN A BETTER WAY!!!!
    for(auto& e: em){
        if (auto pEnemyModel = dynamic_cast<PEnemyModel*>(e.get())) {
            auto pev = std::make_shared<PEnemyViewGraphical>();
            pev->setPEnemyModel(std::make_shared<PEnemyModel>(*pEnemyModel));
            enemyViews.push_back(pev);
        } else if(auto enemyModel = dynamic_cast<EnemyModel*>(e.get())){
            auto ev = std::make_shared<EnemyViewGraphical>();
            ev->setEnemyModel(std::make_shared<EnemyModel>(*enemyModel));
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

void GameController::addNewView(std::unique_ptr<GameView> gv)
{

    allGameViews.push_back(std::move(gv));

}

void GameController::switchView()
{

    gameView->clearMainWindow();
    getNewView();
    //for each view I have to set the model
    gameView->getProtView()->setProtModel(protController->getProtModel());
    gameView->getHpView()->setHpModel(hpController->getHpModel());
    gameView->getTileView()->setTileModel(tileController->getTileModel());

    auto evs = gameView->getEnemyView();
    auto ems = enemyController->getAllEnemyModels();
    for(auto& ev: evs){
        //check the view type:
        if (auto enemyV = dynamic_cast<EnemyView*>(ev.get())) {
            enemyV->setEnemyModel(enemyController->getEnemyModel());
        }
        if (auto enemyV = dynamic_cast<PEnemyView*>(ev.get())) {
            enemyV->setPEnemyModel(enemyController->getPEnemyModel());
        }

    }

    initializeView();
    tileController->update();
    hpController->refreshAll();
    protController->refreshAll();
    enemyController->refreshAllGraphical();
    tileController->update(row, col);


}


void GameController::getNewView()
{
    allGameViews.push_back(std::move(gameView));
    gameView = std::move(allGameViews.front());
    allGameViews.pop_front();
}




