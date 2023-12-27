#include "penemyviewgraphical.h"
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

PEnemyViewGraphical::PEnemyViewGraphical()

{
    enemyType = "PEnemy";
}

void PEnemyViewGraphical::render()
{
    // First, remove all displayed enemies from the scene and the map
    for(auto& item : penemiesDisplayed){
        scene->removeItem(item.second.get());
    }
    penemiesDisplayed.clear();

    // Then fetch all enemy data from the EnemyModel
    auto allPEnemiesState = penemyModel->getAllPEnemyStates();

    // Then display each enemy
    for(auto& penemyState : allPEnemiesState){
        displayPEnemy(penemyState.x, penemyState.y, penemyState.isDefeated);
    }
}


void PEnemyViewGraphical::render(int x, int y)
{
    // First we remove the icon for that enemy in our displayed enemies if there is one.
    auto oldItem = penemiesDisplayed.find(std::make_pair(x/tileDim, y/tileDim));
    
    if(oldItem != penemiesDisplayed.end()){
        scene->removeItem(oldItem->second.get());
        penemiesDisplayed.erase(oldItem);
    }
    
    // Then we fetch data for this Enemy from the EnemyModel.
    auto penemyState = penemyModel->getOnePEnemyState(x, y);

    // Then we render the Enemy if we have data for it.
    if(penemyState.has_value()){
        displayPEnemy(x, y, penemyState.value().isDefeated);
    }
}

void PEnemyViewGraphical::clearView()
{
    if (scene != nullptr) {
        scene.reset();
    }

}

void PEnemyViewGraphical::setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel)
{
    penemyModel = newPenemyModel;
}


void PEnemyViewGraphical::displayPEnemy(int x, int y, bool defeated)
{
    QPixmap penemyIconAlive = QPixmap(":/PEnemy_alive");
    QPixmap penemyIconDefeated = QPixmap(":/PEnemy_dead");
    std::shared_ptr<QGraphicsPixmapItem> icon;

    if (defeated) {
        icon = std::make_shared<QGraphicsPixmapItem>(penemyIconDefeated);
    } else {
        icon = std::make_shared<QGraphicsPixmapItem>(penemyIconAlive);
    }

    icon->setPos(x * tileDim, y * tileDim);
    icon->setZValue(zValue);
    scene->addItem(icon.get());
    
    // Add the shared_ptr to the enemiesDisplayed map
    penemiesDisplayed[std::make_pair(x, y)] = icon;
}
