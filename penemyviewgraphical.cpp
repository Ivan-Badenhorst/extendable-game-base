#include "penemyviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

PEnemyViewGraphical::PEnemyViewGraphical(MainWindow& mw, std::shared_ptr<PEnemyModel> pem)
:mainWindow(mw), penemyModel(pem)
{

}

void PEnemyViewGraphical::update()
{
    penemyDisplays.clear();

    auto enemyIcon = QPixmap(":/PEnemy_alive");

    for(auto& penemy: penemyModel->getEnemies()){
        displayEnemy(std::make_shared<QGraphicsPixmapItem>(enemyIcon), penemy.get()->getXPos(), penemy.get()->getYPos());
    }
}

void PEnemyViewGraphical::displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y)
{
    icon->setPos(x*tileDim, y*tileDim);
    icon->setZValue(zValue);
    mainWindow.getScene()->addItem(icon.get());
    penemyDisplays.push_back(icon);
}
