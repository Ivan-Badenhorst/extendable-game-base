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
    enemySet.insert({enemy->getXPos(), enemy->getYPos(), 
                    enemy->getDefeated(), enemy->getValue(), 
                    pEnemy->getPoisonLevel(), pEnemy->getPoisonLevel()});
}

bool PEnemyModel::containsEnemy(int row, int col)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = row;
    queryEnemyState.y = col;

    // Check if the enemySet contains the enemy
    if (enemySet.find(queryEnemyState) != enemySet.end())
    {
        // Return true if the enemySet contains the enemy
        return true;
    }
    else
    {
        // Return false if the enemySet does not contain the enemy
        return false;
    }
}

bool PEnemyModel::isDefeated(int row, int col)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = row;
    queryEnemyState.y = col;

    // Find the enemy in the set
    auto it = enemySet.find(queryEnemyState);

    if (it != enemySet.end())
    {
        // The enemy was found, return its defeated status
        return it->isDefeated;
    }
    else
    {
        // The enemy was not found, return false
        return false;
    }
}

void PEnemyModel::attackEnemy(int row, int col, int damage)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = row;
    queryEnemyState.y = col;

    // Find the enemy in the set
    auto it = enemySet.find(queryEnemyState);

    if (it != enemySet.end())
    {
        // The enemy was found, create a new PEnemyState with the updated status
        PEnemyState updatedEnemyState = *it;
        updatedEnemyState.isDefeated = true;

        // Erase the old enemy and insert the updated one
        enemySet.erase(it);
        enemySet.insert(updatedEnemyState);
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


std::optional<PEnemyState> PEnemyModel::getOnePEnemyState(int row, int col) const
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = row;
    queryEnemyState.y = col;

    // Find the enemy in the set
    auto it = enemySet.find(queryEnemyState);

    if (it != enemySet.end())
    {
        // The enemy was found, return it wrapped in a std::optional
        return std::optional<PEnemyState>{*it};
    }
    else
    {
        // The enemy was not found, return an empty std::optional
        return std::nullopt;
    }
}

std::vector<PEnemyState> PEnemyModel::getAllPEnemyStates() const
{
    // Create a vector to hold the enemy states
    std::vector<PEnemyState> enemyStates;

    // Iterate over the set and add each enemy state to the vector
    for (const PEnemyState& enemyState : enemySet)
    {
        enemyStates.push_back(enemyState);
    }

    return enemyStates;
}
