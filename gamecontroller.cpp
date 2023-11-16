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
    auto easy = easyLevelFactory.createWorld(mw);
    //EasyLevel* easy = std::static_pointer_cast<EasyLevel>(es);
    std::cout << "made level" << std::endl;

    auto tileController = easy.getTileController();
    tileController->update();
    std::cout << "called update" << std::endl;

}





