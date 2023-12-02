#include "protagonistviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>



ProtagonistViewGraphical::ProtagonistViewGraphical(std::shared_ptr<ProtagonistModel> pm)
    : protModel(pm)
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
    auto prot = QPixmap(":/prisoner");
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

void ProtagonistViewGraphical::setHealthBar(const std::shared_ptr<HealthProgressBar> newHealthBar)
{
    healthBar = newHealthBar;
    updateHealth();
}

void ProtagonistViewGraphical::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}


