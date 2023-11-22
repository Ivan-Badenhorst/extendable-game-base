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
    // do shit
    auto prot = QPixmap(":/prisoner");
    auto protIcon = std::make_shared<QGraphicsPixmapItem>(prot);
    protIcon->setZValue(1.1);

    // set pos protIcon->setPos(*tileDim, hp[1]*tileDim);
    protagonistDisplay = protIcon;
    mainWindow.getScene()->addItem(protagonistDisplay.get());

}

