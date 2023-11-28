#include "HealthPackH/healthpackviewgraphical.h"

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>


#include <QCoreApplication>

HealthPackViewGraphical::HealthPackViewGraphical(std::shared_ptr<HealthPackModel> hpm)
    :hpModel(hpm)
{

}

void HealthPackViewGraphical::update()
{
    healthpackDisplays.clear();


    auto icon1 = QPixmap(":/HealthPackUsed");
    auto icon2 = QPixmap(":/HealthPackFull");


    for(auto& hp: hpModel->getHealthPacks()){

        if(hp[2]>0){//unused pack
            displayHp(std::make_shared<QGraphicsPixmapItem>(icon2), hp);
        }
        else
        {
            displayHp(std::make_shared<QGraphicsPixmapItem>(icon1), hp);
        }

    }


}

void HealthPackViewGraphical::update(int row, int col, bool used)
{
    //std::cout << "Update called: " << row << ";" << col << std::endl;
    auto icon1 = QPixmap(":/HealthPackUsed");
    auto icon2 = QPixmap(":/HealthPackFull");

    std::shared_ptr<QGraphicsPixmapItem> itemsToRerender;
    for(auto& hp: healthpackDisplays){
        int colDisplay = hp.get()->y()/tileDim;
        int rowDisplay = hp.get()->x()/tileDim;

        if(colDisplay == col && rowDisplay == row){
            itemsToRerender = hp;
        }
    }

    scene->removeItem(itemsToRerender.get());
    itemsToRerender.reset();

    if(used){
        displayHp(std::make_shared<QGraphicsPixmapItem>(icon1), std::array<int, 3>{row, col, 0});
    }
    else
    {
        displayHp(std::make_shared<QGraphicsPixmapItem>(icon2), std::array<int, 3>{row, col, 1});
    }

}

void HealthPackViewGraphical::displayHp(std::shared_ptr<QGraphicsPixmapItem> icon, std::array<int, 3> hp)
{
    icon->setPos(hp[1]*tileDim, hp[0]*tileDim);
    icon->setZValue(zValue);
    healthpackDisplays.push_back(icon);
    scene->addItem(icon.get());
}

void HealthPackViewGraphical::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}
