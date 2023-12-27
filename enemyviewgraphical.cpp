
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "enemyviewgraphical.h"

EnemyViewGraphical::EnemyViewGraphical()

{
    enemyType = "Enemy";
}

void EnemyViewGraphical::render()
{
    // First, remove all displayed enemies from the scene and the map
    for(auto& item : enemiesDisplayed){
        scene->removeItem(item.second.get());
    }
    enemiesDisplayed.clear();

    // Then fetch all enemy data from the EnemyModel
    auto allEnemiesState = enemyModel->getAllEnemyStates();

    // Then display each enemy
    for(auto& enemyState : allEnemiesState){
        displayEnemy(enemyState.x, enemyState.y, enemyState.isDefeated);
    }
}

void EnemyViewGraphical::render(int x, int y)
{
    // First we remove the icon for that enemy in our displayed enemies if there is one.
    auto oldItem = enemiesDisplayed.find(std::make_pair(x/tileDim, y/tileDim));
    
    if(oldItem != enemiesDisplayed.end()){
        scene->removeItem(oldItem->second.get());
        enemiesDisplayed.erase(oldItem);
    }
    
    // Then we fetch data for this Enemy from the EnemyModel.
    auto enemyState = enemyModel->getOneEnemyState(x, y);

    // Then we render the Enemy if we have data for it.
    if(enemyState.has_value()){
        displayEnemy(x, y, enemyState.value().isDefeated);
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


void EnemyViewGraphical::displayEnemy(int x, int y, bool defeated)
{
    QPixmap enemyIconAlive = QPixmap(":/Enemy_alive");
    QPixmap enemyIconDefeated = QPixmap(":/Enemy_dead");
    std::shared_ptr<QGraphicsPixmapItem> icon;

    if (defeated) {
        icon = std::make_shared<QGraphicsPixmapItem>(enemyIconDefeated);
    } else {
        icon = std::make_shared<QGraphicsPixmapItem>(enemyIconAlive);
    }

    icon->setPos(x * tileDim, y * tileDim);
    icon->setZValue(zValue);
    scene->addItem(icon.get());
    
    // Add the shared_ptr to the enemiesDisplayed map
    enemiesDisplayed[std::make_pair(x, y)] = icon;
}
