#include "enemymodel.h"

EnemyModel::EnemyModel()
{
    // The model is empty when created. Enemies are added using the addEnemy method from the factory.
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

bool EnemyModel::containsEnemy(int col, int row)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(col, row);

    // Check if the enemyMap contains the key
    return (enemyMap.count(key)>0);
}

bool EnemyModel::isDefeated(int col, int row)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(col, row);

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

void EnemyModel::attackEnemy(int col, int row, int damage)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(col, row);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Attack the enemy
        enemyMap[key]->setDefeated(true);
    }
}

bool EnemyModel::getDefeated(int row, int col) const
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(col, row);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Return the defeated status of the enemy
        return enemyMap.at(key)->getDefeated();
    }
    else
    {
        // Return false if the enemy is not in the map
        return false;
    }
}

EnemyState EnemyModel::getOneEnemyState(int col, int row) const
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(col, row);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Return the enemy state
        return {enemyMap.at(key)->getXPos(), enemyMap.at(key)->getYPos(), enemyMap.at(key)->getDefeated()};
    }
    else
    {
        // Return an empty enemy state if the enemy is not in the map
        return {0, 0, false};
    }
}

std::vector<EnemyState> EnemyModel::getAllEnemyStates() const
{
    // Create a vector to hold the enemy states
    std::vector<EnemyState> enemyStates;

    // Iterate through the enemyMap and add the enemy states to the vector
    for (auto const& x : enemyMap)
    {
        enemyStates.push_back({x.second->getXPos(), x.second->getYPos(), x.second->getDefeated()});
    }

    // Return the vector
    return enemyStates;
}
