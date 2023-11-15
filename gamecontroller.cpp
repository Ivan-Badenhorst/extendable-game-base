#include "gamecontroller.h"

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
    Level easy = easyLevelFactory.createWorld(mw);
    easy.getTileController()->update();

}





