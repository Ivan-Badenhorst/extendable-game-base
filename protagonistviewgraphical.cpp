#include "protagonistviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>



ProtagonistViewGraphical::ProtagonistViewGraphical()
{
    //updateHealth();
}

void ProtagonistViewGraphical::update()
{
    auto xPos = protModel->getPositionX();
    auto yPos = protModel->getPositionY();
    update(xPos,yPos);

//    auto prot = QPixmap(":/prisoner");
//    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
//    protIcon->setZValue(1.1);


//    protagonistDisplay = protIcon;
//    scene->addItem(protagonistDisplay.get());

}

void ProtagonistViewGraphical::update(int row, int col)
{
    if(protModel->getEnergy() >0){
        prot =  QPixmap(":/prisoner");
    }
    else{
        prot = QPixmap(":/prisoner_dead");
    }

    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    scene->removeItem(protagonistDisplay.get());
    protagonistDisplay.reset();


    protIcon->setPos(col*tileDim, row*tileDim);
    protIcon->setZValue(1.1);

    protagonistDisplay = protIcon;
    scene->addItem(protagonistDisplay.get());

}

void ProtagonistViewGraphical::updateHealth()
{
    healthBar->setMaximum(protModel->getMaxhealth());
    healthBar->setValue(protModel->getCurrentHealth());
}

void ProtagonistViewGraphical::updateEnergy()
{
    energyBar->setMaximum(protModel->getMaxEnergy());
    energyBar->setValue(protModel->getEnergy());
}

void ProtagonistViewGraphical::clearView()
{
    scene.reset();
    healthBar.reset();
}

void ProtagonistViewGraphical::setHealthBar(const std::shared_ptr<HealthProgressBar> newHealthBar)
{
    healthBar = newHealthBar;
    updateHealth();
}

void ProtagonistViewGraphical::setEnergyBar(const std::shared_ptr<EnergyProgressBar> newEnergyBar)
{
    energyBar = newEnergyBar;
    updateEnergy();
}

void ProtagonistViewGraphical::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

void ProtagonistViewGraphical::setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel)
{
    protModel = newProtModel;
}


