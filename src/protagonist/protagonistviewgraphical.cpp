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

}

void ProtagonistViewGraphical::update(int row, int col)
{
    if(protModel->getEnergy() >0 && protModel->getCurrentHealth() > 0){
        prot =  QPixmap(":/protagonist/prisoner_0");
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

void ProtagonistViewGraphical::performAttack(int currentFrame)
{
    QString frameImage = QString(":/protagonist/prisoner_%1").arg(currentFrame);

    prot = QPixmap(frameImage);


    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    scene->removeItem(protagonistDisplay.get());
    protagonistDisplay.reset();

    // Update the display with the new frame
    protIcon->setPos(protModel->getPositionY() * tileDim, protModel->getPositionX() * tileDim);
    protIcon->setZValue(1.1);

    protagonistDisplay = protIcon;
    scene->addItem(protagonistDisplay.get());
}

void ProtagonistViewGraphical::performHealthGain(int currentFrame)
{
    prot = currentFrame==0? QPixmap(":/protagonist/prisoner_health"): QPixmap(":/protagonist/prisoner_0");;

    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    scene->removeItem(protagonistDisplay.get());
    protagonistDisplay.reset();

    // Update the display with the new frame
    protIcon->setPos(protModel->getPositionY() * tileDim, protModel->getPositionX() * tileDim);
    protIcon->setZValue(1.1);

    protagonistDisplay = protIcon;
    scene->addItem(protagonistDisplay.get());

}

void ProtagonistViewGraphical::performDeath(int currentFrame)
{
    QString frameImage = QString(":/protagonist/prisoner_dead_%1").arg(currentFrame);

    prot = QPixmap(frameImage);


    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    scene->removeItem(protagonistDisplay.get());
    protagonistDisplay.reset();

    // Update the display with the new frame
    protIcon->setPos(protModel->getPositionY() * tileDim, protModel->getPositionX() * tileDim);
    protIcon->setZValue(1.1);

    protagonistDisplay = protIcon;
    scene->addItem(protagonistDisplay.get());

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


