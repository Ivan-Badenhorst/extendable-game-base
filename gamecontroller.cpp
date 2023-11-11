#include "gamecontroller.h"

GameController::GameController()
{

}


GameController& GameController::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (gameControllerInstance == nullptr)
    {
        gameControllerInstance = new GameController();
    }
    return *gameControllerInstance;

}

