#include "enemymodel.h"
#include <iostream>

EnemyModel::EnemyModel(int w_rows, int w_cols)
{
    world_rows = w_rows;
    world_cols = w_cols;
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

float EnemyModel::getStrength(int x, int y) const
{
    EnemyState queryEnemyState = {x, y, false, 0};
    auto it = enemySet.find(queryEnemyState);
    if (it != enemySet.end())
    {
        return it->strength;
    }
    
    return 0;
}

float EnemyModel::isEnemyAround(int x, int y) 
{
    // Up coordinate
    int up_x = x;
    int up_y = y - 1;

    // Down coordinate
    int down_x = x;
    int down_y = y + 1;

    // Left coordinate
    int left_x = x - 1;
    int left_y = y;

    // Right coordinate
    int right_x = x + 1;
    int right_y = y;

    float damage = 0;

    // Check up
    if (up_y >= 0 && !isDefeated(up_x, up_y))
    {
        damage += getStrength(up_x, up_y);
    }

    // Check down
    if (down_y < world_rows && !isDefeated(down_x, down_y))
    {
        damage += getStrength(down_x, down_y);
    }

    // Check left
    if (left_x >= 0 && !isDefeated(left_x, left_y))
    {
        damage += getStrength(left_x, left_y);
    }

    // Check right
    if (right_x < world_cols && !isDefeated(right_x, right_y))
    {
        damage += getStrength(right_x, right_y);
    }

    return damage;

}

bool EnemyModel::isCompleted()
{
   //iterate over the enemySet and check if all enemies are defeated
    for (const auto& enemyState : enemySet)
    {
         if (!enemyState.isDefeated)
         {
              return false;
         }
    }
    return true;
}
