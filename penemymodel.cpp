#include "penemymodel.h"

PEnemyModel::PEnemyModel()
{
    // The model is empty when created. Enemies are added using the addEnemy method from the factory.
}

void PEnemyModel::addEnemy(std::shared_ptr<Enemy> enemy)
{
    // Get the x and y position of the enemy
    int x = enemy->getXPos();
    int y = enemy->getYPos();

    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Add the enemy to the enemyMap with the key
    enemyMap[key] = enemy;
}

std::vector<std::shared_ptr<Enemy>> PEnemyModel::getEnemies() const
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

bool PEnemyModel::containsEnemy(int row, int col)
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

bool PEnemyModel::isDefeated(int row, int col)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(row, col);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key) > 0)
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

void PEnemyModel::attackEnemy(int row, int col, int damage)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(row, col);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key) > 0)
    {
        // Attack the enemy
        enemyMap[key]->setDefeated(true);
    }
}

void PEnemyModel::drainPEnemy(int row, int col)
{

}

int PEnemyModel::calculateFireState(float poisonLevel) const
{
    // Assuming 0-24: Fire1, 25-49: Fire2, 50-74: Fire3, 75-100: Fire4
    return static_cast<int>(poisonLevel / 25) + 1;
}


    

float getPoisonLevel(int row, int col) 
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(row, col);

    // // Check if the enemyMap contains the key
    // if (enemyMap.count(key) > 0)
    // {
    //     // Attack the enemy
    //     enemyMap[key]->setDefeated(true);
    // }

    // // Check if the enemyMap contains the key
    // if (enemyMap.count(key) > 0)
    // {
    //     // Cast the enemy to PEnemy and call its getPoisonLevel method
    //     auto pEnemy = dynamic_cast<PEnemy*>( enemyMap[key] );
    //     if (pEnemy)
    //     {
    //         return pEnemy->getPoisonLevel();
    //     }
    // }

    // Return 0 if the enemy is not in the map or is not of type PEnemy
    return 0;
}

