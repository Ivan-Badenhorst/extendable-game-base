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
    ///THIS FUNCTION CURRENTLY USES REGULAR POINTERS
    /// NO MEMORY MANAGEMENT!! IS SHOULD CHECK IT!!
    /// CAN WE IMPROVE IT???
    auto icon = QPixmap(":/HealthPackFull");

    for(auto& hp: hpModel->getHealthPacks()){

        QGraphicsPixmapItem *iconItem = new QGraphicsPixmapItem(icon);
        iconItem->setZValue(1.1);
        iconItem->setPos(hp[0]*tileDim, hp[1]*tileDim);
        mainWindow.getScene()->addItem(iconItem);

    }






}
