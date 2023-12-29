#include "enemymodel.h"
#include <iostream>

EnemyModel::EnemyModel()
{
    enemyType = "Enemy";
}

void EnemyModel::addEnemy(std::unique_ptr<Enemy> enemy)
{
    EnemyState enemyState = {enemy->getXPos(), enemy->getYPos(), enemy->getDefeated(), enemy->getValue()};
    enemySet.insert(enemyState);
}


bool EnemyModel::containsEnemy(int x, int y)
{
    EnemyState queryEnemyState = {x, y, false, 0};
    return enemySet.find(queryEnemyState) != enemySet.end();
}

bool EnemyModel::isDefeated(int x, int y)
{
    EnemyState queryEnemyState = {x, y, false, 0};
    auto it = enemySet.find(queryEnemyState);
    if (it != enemySet.end())
    {
        return it->isDefeated;
    }
    else
    {
        return false;
    }
}

void EnemyModel::attackEnemy(int x, int y, int damage)
{
    EnemyState queryEnemyState = {x, y, false, 0};
    auto it = enemySet.find(queryEnemyState);
    if (it != enemySet.end())
    {
        EnemyState updatedEnemyState = *it;
        updatedEnemyState.isDefeated = true;
        enemySet.erase(it);
        enemySet.insert(updatedEnemyState);
    }
}


std::optional<EnemyState> EnemyModel::getOneEnemyState(int x, int y) const
{
    EnemyState queryEnemyState = {x, y, false, 0};
    auto it = enemySet.find(queryEnemyState);
    if (it != enemySet.end())
    {
        return std::optional<EnemyState>{*it};
    }
    else
    {
        return std::nullopt;
    }
}

std::vector<EnemyState> EnemyModel::getAllEnemyStates() const
{
    std::vector<EnemyState> allEnemyStates;
    for (const auto& enemyState : enemySet)
    {
        allEnemyStates.push_back(enemyState);
    }
    return allEnemyStates;
}