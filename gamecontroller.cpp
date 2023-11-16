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
    //EasyLevel* easy = std::static_pointer_cast<EasyLevel>(es);

    //auto easyLevel = std::unique_ptr<EasyLevel>(dynamic_cast<EasyLevel*>(level.release()));
    //auto easyLevel = std::make_unique<EasyLevel>(*level);
    //auto easyLevel = std::unique_ptr<EasyLevel>(static_cast<EasyLevel*>(level.release()));

    std::cout << "made level" << std::endl;

    auto tileController = easyLevel->getTileController();
    tileController->update();
    std::cout << "called update" << std::endl;

}





