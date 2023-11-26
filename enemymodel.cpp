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

bool EnemyModel::containsEnemy(int row, int col)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(row, col);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key) > 0)
    {
        // Return true if the enemyMap contains the key
        return true;
    }
    else
    {
        // Return false if the enemyMap does not contain the key
        return false;
    }
}
