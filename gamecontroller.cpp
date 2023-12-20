#include "gamecontroller.h"
#include "HealthPackH/healthpackviewgraphical.h"
#include "enemyviewgraphical.h"
#include "mediumlevelfactory.h"
#include "penemymodel.h"
#include "enemymodel.h"
#include "penemyviewgraphical.h"
#include "penemyviewtext.h"
#include "protagonistviewgraphical.h"

#include <iostream>
#include <memory>

#include <thread>
#include <chrono>
#include <QCoreApplication>
#include <QEventLoop>
#include <QMessageBox>



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


    if (enemyController->containsEnemy(col, row) && !(enemyController->isDefeated(col, row)))
    {
        enemyController->attackEnemy(col, row, protController->getAttackDamage());
        isHealthOver = protController->updateHealth(-10); //does fixed damage now
        row = prevRow;
        col = prevCol;
    }


    int hpVal = hpController->update(row, col);
    if (hpVal > 0)  {
        protController->updateHealth(hpVal);
    }
    protController->update(row, col);
    float tileVal=tileController->getEnergy(row, col);
    if (tileVal > 0) {
        isEnergyOver = protController->updateEnergy(tileVal);
    }
    if(isHealthOver || isEnergyOver){
        stopGame("GAME OVER", "You Lose! Protagonist Has Died");

    }

    hpController->update(prevRow, prevCol);
    tileController->update(row, col);
}

void GameController::stopGame(QString title, QString message)
{
    protController->refreshAll();
    QMessageBox::information(nullptr, title, message);
    isInputDisabled = true;
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

    auto easyLevelFactory = std::make_shared<EasyLevelFactory>();
    LevelControllers controllers;
    std::pair<std::shared_ptr<LevelFactory>, LevelControllers> level(easyLevelFactory, controllers);

    levels.push_back(level);
    auto easyLevel = easyLevelFactory->createWorld();

    tileController = easyLevel->getTileController();

    auto [h, w] = tileController->getDimensions();
    height = h;
    width = w;

    isInputDisabled = false;

    if(levels.size() > 1) tileController->addPortal(h-1, w-1, true);


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
            pev->setEnemyType("PEnemy");
            pev->setPEnemyModel(std::make_shared<PEnemyModel>(*pEnemyModel));
            enemyViews.push_back(pev);
        } else if(auto enemyModel = dynamic_cast<EnemyModel*>(e.get())){
            auto ev = std::make_shared<EnemyViewGraphical>();
            ev->setEnemyType("Enemy");
            ev->setEnemyModel(std::make_shared<EnemyModel>(*enemyModel));
            enemyViews.push_back(ev);
        }
    }
    gameView->setEnemyView(enemyViews);

    initializeView();


    hpController->refreshAll();
    protController->refreshAll();
    enemyController->refreshAllGraphical();
    tileController->update(0, 0, false);

}

void GameController::initializeView()
{
    gameView->initializeMainWindow();
    tileController->setTileView(gameView->getTileView());
    protController->setProtView(gameView->getProtView());
    enemyController->setEnemyView(gameView->getEnemyView());
    hpController->setHpView(gameView->getHpView());

}


bool GameController::getIsInputDisabled() const
{
    return isInputDisabled;
}


void GameController::addNewView(std::unique_ptr<GameView> gv)
{

    allGameViews.push_back(std::move(gv));

}

void GameController::switchView(bool change)
{


    if(change){
        gameView->clearMainWindow();
        getNewView();
    }
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
    tileController->update(row, col,false);
    hpController->refreshAll();
    protController->refreshAll();
    enemyController->refreshAllGraphical();
//    tileController->update(row, col);
    protController->update(row, col);
//    tileController->update(row, col, false);

}


void GameController::getNewView()
{
    allGameViews.push_back(std::move(gameView));
    gameView = std::move(allGameViews.front());
    allGameViews.pop_front();
}



void GameController::switchLevel(std::shared_ptr<LevelFactory> &levelFactory)
{
    auto level = levelFactory->createWorld();
    //UPDAGTE MY CONTROLLER POINTERS


    tileController = level->getTileController();
    hpController = level->getHpController();
    protController = level->getProtController();
    enemyController = level->getEnemyController();
    //UPDATE ROW COL, WIDTH HEIGHT AS WELL!!!!!!


    setupUi();
    tileController->addPortal(0,0,false);
    tileController->addPortal(height-1, width-1, true);
}

void GameController::nextLevel()
{
    int previousLevel = currentLevel;
    if(currentLevel < levels.size()-1){
        currentLevel+=1;
    }
    else{
        stopGame("Game Complete!", "You win! Well done!");
        return;
    }


    //cache current
    ///CHECK IF I CAN CHANGE THIS TO ONLY CHANGE IF IT HASN'T BEEN SAVED BEFORE!!!!

    levels[previousLevel].second.enemyController = enemyController;
    levels[previousLevel].second.hpController = hpController;
    levels[previousLevel].second.protController = protController;
    levels[previousLevel].second.tileController = tileController;
    levels[previousLevel].second.initialized = true;

    if(levels[currentLevel].second.initialized){

        tileController = levels[currentLevel].second.tileController;
        hpController = levels[currentLevel].second.hpController;
        protController = levels[currentLevel].second.protController;
        enemyController = levels[currentLevel].second.enemyController;

        setupUi();
    }
    else{
        auto levelFactory = levels[currentLevel].first;
        switchLevel(levelFactory);
        switchView(false);
    }

}

void GameController::setupUi()
{
    auto [h, w] = tileController->getDimensions();
    height = h;
    width = w;
    row = 0;
    col = 0;

    gameView->clearMainWindow();
    QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    switchView(false);
}

void GameController::previousLevel()
{
    int previousLevel = currentLevel;
    if(currentLevel > 0){
        currentLevel-=1;
    }
    else return;

    levels[previousLevel].second.enemyController = enemyController;
    levels[previousLevel].second.hpController = hpController;
    levels[previousLevel].second.protController = protController;
    levels[previousLevel].second.tileController = tileController;
    levels[previousLevel].second.initialized = true;

    if(levels[currentLevel].second.initialized){

        tileController = levels[currentLevel].second.tileController;
        hpController = levels[currentLevel].second.hpController;
        protController = levels[currentLevel].second.protController;
        enemyController = levels[currentLevel].second.enemyController;

        setupUi();

    }
    else{
        auto levelFactory = levels[currentLevel];
        //switchLevel(levelFactory);
        switchView(false);
    }

    row = height-1;
    col = width-1;
    tileController->update(row, col, false);
    protController->update(row, col);

}

void GameController::addLevel(const std::shared_ptr<LevelFactory> &level)
{
    LevelControllers controllers;
    std::pair<std::shared_ptr<LevelFactory>, LevelControllers> newLevel(level, controllers);

    levels.push_back(newLevel);
//    levels.push_back(level);
}




