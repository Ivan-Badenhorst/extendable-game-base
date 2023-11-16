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
    std::cout << "made factory" << std::endl;
    auto level = easyLevelFactory.createWorld(mw);
    EasyLevel* easyLevel = static_cast<EasyLevel*>(level);

    std::cout << "made level" << std::endl;

    auto tileController = easyLevel->getTileController();
    tileController->update();
    std::cout << "called update" << std::endl;

    delete easyLevel;

}





