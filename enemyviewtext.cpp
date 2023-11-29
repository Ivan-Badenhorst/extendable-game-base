#include "enemyviewtext.h"

EnemyViewText::EnemyViewText(std::shared_ptr<EnemyModel> em)
:enemyModel(em)
{

}

void EnemyViewText::update()
{

}

void EnemyViewText::clearView()
{

}

void EnemyViewText::setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel)
{
    enemyModel = newEnemyModel;
}

