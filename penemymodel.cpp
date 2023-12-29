#include "penemymodel.h"

PEnemyModel::PEnemyModel()
{
    enemyType = "PEnemy";
}

void PEnemyModel::addEnemy(std::unique_ptr<Enemy> enemy)
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(enemy->getXPos(), enemy->getYPos());

    auto pEnemy = dynamic_cast<PEnemy*>(enemy.get());

    // Add the enemy to the enemyMap with the key
    enemyMap[key] = {enemy->getXPos(), enemy->getYPos(), 
                        enemy->getDefeated(), enemy->getValue(),
                        pEnemy->getPoisonLevel(), pEnemy->getPoisonLevel()};
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
        return enemyMap[key].isDefeated;
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
        enemyMap[key].isDefeated = true;
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


std::optional<PEnemyState> PEnemyModel::getOnePEnemyState(int x, int y) const
{
    // Create a pair with the x and y position as the key
    std::pair<int, int> key = std::make_pair(x, y);

    // Check if the enemyMap contains the key
    if (enemyMap.count(key)>0)
    {
        // Return the enemy state
        return std::optional<PEnemyState>({enemyMap.at(key).x, enemyMap.at(key).y,
         enemyMap.at(key).isDefeated, enemyMap.at(key).strength,
         enemyMap.at(key).initialPoisonLevel, enemyMap.at(key).currentPoisonLevel});
    }
    else
    {
        // Return an empty optional if the enemy is not in the map
        return std::nullopt;
    }
}

std::vector<PEnemyState> PEnemyModel::getAllPEnemyStates() const
{
    // Create a vector to hold the enemy states
    std::vector<PEnemyState> enemyStates;

    // Iterate through the enemyMap and add the enemy states to the vector
    for (auto const& e : enemyMap)
    {
        enemyStates.push_back({e.second.x, e.second.y, e.second.isDefeated,
         e.second.strength, e.second.initialPoisonLevel, e.second.currentPoisonLevel});
    }

    // Return the vector
    return enemyStates;
}
