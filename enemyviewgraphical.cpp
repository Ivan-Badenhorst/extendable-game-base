
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "enemyviewgraphical.h"

EnemyViewGraphical::EnemyViewGraphical(MainWindow& mw, std::shared_ptr<EnemyModel> em)
:mainWindow(mw), enemyModel(em)
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

void EnemyViewGraphical::displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y)
{
    icon->setPos(x*tileDim, y*tileDim);
    icon->setZValue(zValue);
    mainWindow.getScene()->addItem(icon.get());
    enemyDisplays.push_back(icon);
}
