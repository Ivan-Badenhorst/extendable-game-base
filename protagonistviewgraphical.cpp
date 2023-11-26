#include "protagonistviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>



ProtagonistViewGraphical::ProtagonistViewGraphical(MainWindow& mw, std::shared_ptr<ProtagonistModel> pm)
    : mainWindow(mw), protModel(pm)
{

}

void ProtagonistViewGraphical::update()
{
    auto prot = QPixmap(":/prisoner");
    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    protIcon->setZValue(1.1);


    protagonistDisplay = protIcon;
    mainWindow.getScene()->addItem(protagonistDisplay.get());

}

void ProtagonistViewGraphical::update(int row, int col)
{
    auto prot = QPixmap(":/prisoner");
    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    mainWindow.getScene()->removeItem(protagonistDisplay.get());
    protagonistDisplay.reset();


    protIcon->setPos(col*tileDim, row*tileDim);
    protIcon->setZValue(1.1);

    protagonistDisplay = protIcon;
    mainWindow.getScene()->addItem(protagonistDisplay.get());

}

