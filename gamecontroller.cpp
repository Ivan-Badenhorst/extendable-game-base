#include "gamecontroller.h"

#include <iostream>

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
    Level easy = easyLevelFactory.createWorld(mw);
    std::cout << "made level" << std::endl;

    auto tileController = easy.getTileController();
    tileController->update();
    std::cout << "called update" << std::endl;

}





