#include "gamecontroller.h"


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

void GameController::input(const ArrowDirection &direction) const
{
    switch (direction) {
    case ArrowDirection::Up:
        std::cout << "Handling Up direction..." << std::endl;
        // Perform actions for Up direction
        break;
    case ArrowDirection::Down:
        std::cout << "Handling Down direction..." << std::endl;
        // Perform actions for Down direction
        break;
    case ArrowDirection::Left:
        std::cout << "Handling Left direction..." << std::endl;
        // Perform actions for Left direction
        break;
    case ArrowDirection::Right:
        std::cout << "Handling Right direction..." << std::endl;
        // Perform actions for Right direction
        break;
    }

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

    std::cout << "start position:" << std::endl;
    tileController->update(0, 0);
    hpController = easyLevel->getHpController();
    hpController->refreshAll();


    /*
    //first wait for render to complete!!!!
    QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    std::this_thread::sleep_for(std::chrono::seconds(2));


    std::cout << "One down" << std::endl;
    tileController->update(1, 0);
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "start position" << std::endl;
    tileController->update(0, 0);
    QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //I will now test the healthpack update -> USING ALL HEALTH PACKS!!!:
    for(int i=0; i< 30; i++){
        for(int j=0; j<30;j++){
            hpController->update(i,j);

        }
    }


//    QRectF areaToShow = QRectF(0, 0, 800, 400);
//    mw.getUi()->graphicsView->setSceneRect(areaToShow);
    tileController->update(29, 29);
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    delete easyLevel;*/

}





