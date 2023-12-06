#include "penemyviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

PEnemyViewGraphical::PEnemyViewGraphical(std::shared_ptr<PEnemyModel> pem)
: penemyModel(pem)
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

void PEnemyViewGraphical::update(int row, int col, bool defeated)
{
    auto enemyIcon = QPixmap(":/PEnemy_alive");
    auto enemyIconDefeated = QPixmap(":/PEnemy_dead");

    std::shared_ptr<QGraphicsPixmapItem> itemsToRerender;
    for(auto& penemy: penemyDisplays){
        int colDisplay = penemy.get()->y()/tileDim;
        int rowDisplay = penemy.get()->x()/tileDim;

        if(colDisplay == row && rowDisplay == col){
            itemsToRerender = penemy;
        }
    }

    scene->removeItem(itemsToRerender.get());
    itemsToRerender.reset();

    if(defeated){
        displayEnemy(std::make_shared<QGraphicsPixmapItem>(enemyIconDefeated), col, row);
    }
    else
    {
        displayEnemy(std::make_shared<QGraphicsPixmapItem>(enemyIcon), col, row);
    }
}


void PEnemyViewGraphical::displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y)
{
    icon->setPos(x*tileDim, y*tileDim);
    icon->setZValue(zValue);
    scene->addItem(icon.get());
    penemyDisplays.push_back(icon);
}
