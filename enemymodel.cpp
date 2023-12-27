#include "enemymodel.h"
#include <iostream>

EnemyModel::EnemyModel()
{
    enemyType = "Enemy";
}

void EnemyModel::addEnemy(std::shared_ptr<Enemy> enemy)
{
    // Get the x and y position of the enemy
    int x = enemy->getXPos();
    int y = enemy->getYPos();

    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Add the enemy to the enemyMap with the key
    enemyMap[key] = enemy;
}

/// TODO: we should not give access to the actual data which should be private to the model !
std::vector<std::shared_ptr<Enemy>> EnemyModel::getEnemies() const
{
    // Create a vector to hold the enemies
    std::vector<std::shared_ptr<Enemy>> enemies;

    // Iterate through the enemyMap and add the enemies to the vector
    for (auto const& x : enemyMap)
    {
        enemies.push_back(x.second);
    }

    // Return the vector
    return enemies;
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
        return enemyMap[key]->getDefeated();
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
        enemyMap[key]->setDefeated(true);
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
        return std::optional<EnemyState>({enemyMap.at(key)->getXPos(), enemyMap.at(key)->getYPos(), enemyMap.at(key)->getDefeated()});
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
        enemyStates.push_back({e.second->getXPos(), e.second->getYPos(), e.second->getDefeated()});
    }

    // Return the vector
    return enemyStates;
}
