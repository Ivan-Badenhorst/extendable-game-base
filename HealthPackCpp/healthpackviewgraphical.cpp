#include "HealthPackH/healthpackviewgraphical.h"

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

HealthPackViewGraphical::HealthPackViewGraphical(MainWindow &mw, std::shared_ptr<HealthPackModel> hpm)
    :mainWindow(mw), hpModel(hpm)
{

}

void HealthPackViewGraphical::update()
{
    healthpackDisplays.clear();
    auto icon1 = QPixmap(":/HealthPackUsed");
    auto icon2 = QPixmap(":/HealthPackFull");

    for(auto& hp: hpModel->getHealthPacks()){

        if(hp[2]>0){//unused pack
            displayHp(std::make_shared<QGraphicsPixmapItem>(icon2));
        }
        else
        {
            displayHp(std::make_shared<QGraphicsPixmapItem>(icon1));
        }

    }

}

void HealthPackViewGraphical::displayHp(std::shared_ptr<QGraphicsPixmapItem> icon)
{
    icon->setZValue(1.1);
    icon->setPos(hp[0]*tileDim, hp[1]*tileDim);
    healthpackDisplays.push_back(icon);
    mainWindow.getScene()->addItem(icon.get());
}
