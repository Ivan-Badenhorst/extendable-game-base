#include "penemymodel.h"

PEnemyModel::PEnemyModel(int w_rows, int w_cols)
{
    world_rows = w_rows;
    world_cols = w_cols;
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

bool PEnemyModel::containsEnemy(int x, int y)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = x;
    queryEnemyState.y = y;

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

bool PEnemyModel::isDefeated(int x, int y)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = x;
    queryEnemyState.y = y;

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

void PEnemyModel::attackEnemy(int x, int y, int damage)
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = x;
    queryEnemyState.y = y;

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


std::optional<PEnemyState> PEnemyModel::getOnePEnemyState(int x, int y) const
{
    // Create a PEnemyState object with the given coordinates
    PEnemyState queryEnemyState;
    queryEnemyState.x = x;
    queryEnemyState.y = y;

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

void PEnemyModel::drainPEnemy(int x, int y)
{
    // We try to deduce poison from the enemy
    if(deducePoison(x, y))
    {
        // If it succeeded, we update the fire set
        auto fires = getPEnemyFire(x, y);

        for (const auto& fire : fires) {
            auto existingFire = fireSet.find(fire);
            if (existingFire != fireSet.end()) {
                // If the fire already exists and its fireType is less than the new one
                if (existingFire->fireType < fire.fireType) {
                    // Remove the old fire from the set
                    fireSet.erase(existingFire);

                    // Insert the new fire into the set
                    fireSet.insert(fire);
                }
            } else {
                // If the fire does not exist in the set, insert it
                fireSet.insert(fire);
            }
        }
    }
}



std::vector<FireOnTile> PEnemyModel::getPEnemyFire(int x, int y) const {
    std::vector<FireOnTile> fires;
    auto it = enemySet.find(PEnemyState{x, y, false, 0, 0, 0});
    if (it != enemySet.end()) {
        int initialStage = getFireStageFromPoisonLevel(it->initialPoisonLevel);
        int currentStage = getFireStageFromPoisonLevel(it->currentPoisonLevel);
        int drainCount = initialStage - currentStage;
        fires = calculateFireTiles(x, y, drainCount);
    }
    return fires;
}

int PEnemyModel::containsFire(int x, int y) const
{
    // Create a FireOnTile object with the given coordinates
    FireOnTile queryFire;
    queryFire.x = x;
    queryFire.y = y;

    // Find the fire in the set
    auto it = fireSet.find(queryFire);

    if (it != fireSet.end())
    {
        // The fire was found, return its fire type
        return it->fireType;
    }
    else
    {
        // The fire was not found, return 0
        return 0;
    }
}

bool PEnemyModel::deducePoison(int x, int y)
{
    auto enemyState = enemySet.find(PEnemyState{x, y, false, 0, 0, 0});
    if (enemyState != enemySet.end() && enemyState->currentPoisonLevel > 0) {
        // Create a copy of the found enemy state
        PEnemyState newEnemyState = *enemyState;

        // Decrease the current poison level by 25, with a minimum value of 0
        newEnemyState.currentPoisonLevel = std::max(0.0f, newEnemyState.currentPoisonLevel - 25);

        // Remove the old enemy state from the set
        enemySet.erase(enemyState);

        // Insert the new enemy state into the set
        enemySet.insert(newEnemyState);

        // Return true as poison was deduced
        return true;
    }

    // Return false as there was no poison to deduce
    return false;
}

int PEnemyModel::getFireStageFromPoisonLevel(int poisonLevel) const
{
    return poisonLevel / 25;
}


std::vector<FireOnTile> PEnemyModel::calculateFireTiles(int x, int y, int drainCount) const {
    std::vector<FireOnTile> fires;

    // We can add multi-threading here later if we want to
    for (int i = 1; i <= drainCount; ++i) {
        // Top side
        for (int j = x - i; j <= x + i; ++j) {
            if (j >= 0 && j < world_rows && y - i >= 0) {
                fires.push_back(FireOnTile{j, y - i, drainCount - i + 1});
            }
        }

        // Bottom side
        for (int j = x - i; j <= x + i; ++j) {
            if (j >= 0 && j < world_rows && y + i < world_cols) {
                fires.push_back(FireOnTile{j, y + i, drainCount - i + 1});
            }
        }

        // Left side
        for (int j = y - i + 1; j < y + i; ++j) {
            if (j >= 0 && j < world_cols && x - i >= 0) {
                fires.push_back(FireOnTile{x - i, j, drainCount - i + 1});
            }
        }

        // Right side
        for (int j = y - i + 1; j < y + i; ++j) {
            if (j >= 0 && j < world_cols && x + i < world_rows) {
                fires.push_back(FireOnTile{x + i, j, drainCount - i + 1});
            }
        }
    }

    return fires;
}