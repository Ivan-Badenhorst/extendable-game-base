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
        displayFire(penemyState.x, penemyState.y);
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
        displayFire(x, y);
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

void PEnemyViewGraphical::displayFire(int x, int y)
{
    QPixmap fire1Icon = QPixmap(":/fire1");
    QPixmap fire2Icon = QPixmap(":/fire2");
    QPixmap fire3Icon = QPixmap(":/fire3");
    QPixmap fire4Icon = QPixmap(":/fire4");

    auto fires = penemyModel->getPEnemyFire(x, y);

    for (const auto& fire : fires) {
        auto oldFire = firesDisplayed.find(std::make_pair(fire.x, fire.y));
        if (oldFire != firesDisplayed.end()) {
            scene->removeItem(oldFire->second.get());
            firesDisplayed.erase(oldFire);
        }

        std::shared_ptr<QGraphicsPixmapItem> icon;
        switch (fire.fireType) {
            case 1:
                icon = std::make_shared<QGraphicsPixmapItem>(fire1Icon);
                break;
            case 2:
                icon = std::make_shared<QGraphicsPixmapItem>(fire2Icon);
                break;
            case 3:
                icon = std::make_shared<QGraphicsPixmapItem>(fire3Icon);
                break;
            case 4:
                icon = std::make_shared<QGraphicsPixmapItem>(fire4Icon);
                break;
        }

        icon->setPos(fire.x * tileDim, fire.y * tileDim);
        icon->setZValue(zValue);
        scene->addItem(icon.get());

        // Add the shared_ptr to the firesDisplayed map
        firesDisplayed[std::make_pair(fire.x, fire.y)] = icon;
    }
}