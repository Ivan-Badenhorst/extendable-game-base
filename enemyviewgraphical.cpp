
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "enemyviewgraphical.h"

EnemyViewGraphical::EnemyViewGraphical()

{

}

void EnemyViewGraphical::update()
{
    enemyDisplays.clear();

    auto enemyIcon = QPixmap(":/Enemy_alive");

    for(auto& enemy: enemyModel->getEnemies()){
        displayEnemy(std::make_shared<QGraphicsPixmapItem>(enemyIcon), enemy.get()->getXPos(), enemy.get()->getYPos());
    }
}

void EnemyViewGraphical::update(int row, int col, bool defeated)
{
    auto enemyIcon = QPixmap(":/Enemy_alive");
    auto enemyIconDefeated = QPixmap(":/Enemy_dead");

    std::shared_ptr<QGraphicsPixmapItem> itemsToRerender;
    for(auto& enemy: enemyDisplays){
        int colDisplay = enemy.get()->y()/tileDim;
        int rowDisplay = enemy.get()->x()/tileDim;

        if(colDisplay == row && rowDisplay == col){
            itemsToRerender = enemy;
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


void EnemyViewGraphical::clearView()
{
    if (scene != nullptr) {
        scene.reset();
    }
}

void EnemyViewGraphical::setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel)
{
    enemyModel = newEnemyModel;
}


void EnemyViewGraphical::displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y)
{
    icon->setPos(x*tileDim, y*tileDim);
    icon->setZValue(zValue);
    scene->addItem(icon.get());
    enemyDisplays.push_back(icon);
}
