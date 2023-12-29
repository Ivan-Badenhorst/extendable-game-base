#include "enemymodel.h"
#include <iostream>

EnemyModel::EnemyModel()
{
    enemyType = "Enemy";
}

void EnemyModel::addEnemy(std::unique_ptr<Enemy> enemy)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(enemy->getXPos(), enemy->getYPos());

    // Add the enemy to the enemyMap with the key
    enemyMap[key] = {enemy->getXPos(), enemy->getYPos(), enemy->getDefeated(), enemy->getValue()};
}


bool EnemyModel::containsEnemy(int x, int y)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Check if the enemyMap contains the key
    return (enemyMap.count(key)>0);
}

bool EnemyModel::isDefeated(int x, int y)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Return the defeated status of the enemy
        return enemyMap[key].isDefeated;
    }
    else
    {
        // Return false if the enemy is not in the map
        return false;
    }
}

void EnemyModel::attackEnemy(int x, int y, int damage)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Attack the enemy
        enemyMap[key].isDefeated = true;
    }
}


std::optional<EnemyState> EnemyModel::getOneEnemyState(int x, int y) const
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Return the enemy state
        return std::optional<EnemyState>(enemyMap.at(key));
    }
    else
    {
        // Return an empty optional if the enemy is not in the map
        return std::nullopt;
    }
}

std::vector<EnemyState> EnemyModel::getAllEnemyStates() const
{
    // Create a vector to hold the enemy states
    std::vector<EnemyState> enemyStates;

    // Iterate through the enemyMap and add the enemy states to the vector
    for (auto const& e : enemyMap)
    {
        enemyStates.push_back(e.second);
    }

    // Return the vector
    return enemyStates;
}
