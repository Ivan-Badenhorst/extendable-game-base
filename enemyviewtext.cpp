#include "enemyviewtext.h"

#include <iostream>

EnemyViewText::EnemyViewText()

{

}

void EnemyViewText::render()
{
    if(enemyModel){
        std::cout << "enemy works!!!" << std::endl;
    }
}

void EnemyViewText::clearView()
{

}

void EnemyViewText::setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel)
{
    enemyModel = newEnemyModel;
}

void EnemyViewText::render(int x, int y)
{

}

