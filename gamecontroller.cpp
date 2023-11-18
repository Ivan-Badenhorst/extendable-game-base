#include "gamecontroller.h"
#include "easylevel.h"

#include "ui_mainwindow.h"

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

    tileController->update(0, 0);

    auto hpController = easyLevel->getHpController();


    //first wait for render to complete!!!!
    QCoreApplication::processEvents(QEventLoop::AllEvents, 50);


    std::this_thread::sleep_for(std::chrono::seconds(2));

    tileController->update(50, 0);
    QCoreApplication::processEvents(QEventLoop::AllEvents, 50);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    tileController->update(50, 50);

    QRectF areaToShow = QRectF(0, 0, 800, 400);
    mw.getUi()->graphicsView->setSceneRect(areaToShow);

    delete easyLevel;

}





