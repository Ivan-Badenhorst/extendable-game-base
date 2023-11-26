#include "gamecontroller.h"

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

    hpController->update(row, col);
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
void GameController::startGame(MainWindow & mw)
{

    EasyLevelFactory easyLevelFactory;
    auto level = easyLevelFactory.createWorld(mw);
    EasyLevel* easyLevel = static_cast<EasyLevel*>(level);

    tileController = easyLevel->getTileController();

    auto [h, w] = tileController->getDimensions();
    height = h;
    width = w;

    tileController->update(0, 0);
    hpController = easyLevel->getHpController();
    hpController->refreshAll();

    protController = easyLevel->getProtController();
    protController->refreshAll();

    enemyController = easyLevel->getEnemyController();
    enemyController->refreshAllGraphical();
    

}





