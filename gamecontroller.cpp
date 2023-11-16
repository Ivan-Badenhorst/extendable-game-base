#include "gamecontroller.h"

#include <iostream>
#include <memory>

GameController*  GameController::gameControllerInstance = nullptr;


GameController::GameController()
{

}

GameController* GameController::getInstance()
{
    if (gameControllerInstance == nullptr)
    {
        gameControllerInstance = new GameController();
    }
    return gameControllerInstance;

}
void GameController::startGame(MainWindow & mw)
{

    EasyLevelFactory easyLevelFactory;
    auto level = easyLevelFactory.createWorld(mw);
    EasyLevel* easyLevel = static_cast<EasyLevel*>(level);


    auto tileController = easyLevel->getTileController();
    tileController->update();


    delete easyLevel;

}





