#include "enemyviewtext.h"

#include <iostream>

EnemyViewText::EnemyViewText()

{

}

void EnemyViewText::update()
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

void EnemyViewText::update(int row, int col, bool defeated)
{

}

