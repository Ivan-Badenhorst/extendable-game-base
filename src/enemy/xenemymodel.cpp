#include "xenemymodel.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>

XEnemyModel::XEnemyModel(int w_rows, int w_cols) 
{
    std::srand(std::time(nullptr)); // seed the random number generator
    world_rows = w_rows;
    world_cols = w_cols;
    enemyType = "XEnemy";
}

void XEnemyModel::addEnemy(std::unique_ptr<Enemy> enemy)
{
    // Not used
}

void XEnemyModel::addXEnemy(int amount)
{
    // Add the given amount of enemies to the enemyVector
    for (int i = 0; i < amount; i++)
    {
        XEnemyState enemy;
        enemy.x = rand() % world_rows;
        enemy.y = rand() % world_cols;
        enemy.isDefeated = false;
        enemy.strength = 100;
        enemyVector.push_back(enemy);
    }
}

bool XEnemyModel::containsEnemy(int x, int y)
{
    // Check if there is an enemy at the given position
    for (const auto& enemy : enemyVector)
    {
        if (enemy.x== x && enemy.y == y)
        {
            return true;
        }
    }
    return false;
}

bool XEnemyModel::isDefeated(int x, int y)
{
    // Check if the enemy at the given position is defeated
    for (const auto& enemy : enemyVector)
    {
        if (enemy.x == x && enemy.y == y)
        {
            return enemy.isDefeated;
        }
    }
    return true; // Return true if there is no enemy at the given position
}

void XEnemyModel::attackEnemy(int x, int y, int damage)
{
    // Attack the enemy at the given position
    for (auto& enemy : enemyVector)
    {
        if (enemy.x == x && enemy.y== y)
        {
            enemy.isDefeated = true;
            break;
        }
    }
}

bool XEnemyModel::follow(int protagonistX, int protagonistY)
{
    bool danger = false;

    // Iterate through the enemyVector and move each enemy
    for (auto& enemy : enemyVector)
    {

        auto moves = tileModel->findPath(enemy.x, enemy.y, protagonistX, protagonistY);
        if(moves.size()<10){
            danger = true;
        }
        if(moves.size()!=0){
            auto move = getNewPos(moves[0], enemy.x, enemy.y);
            enemy.x = move.first;
            enemy.y = move.second;
        }
        else{
            std::cout<< "Size 0" << std::endl;
        }
        std::cout << "XEnemy in position " << enemy.x << ":" << enemy.y << std::endl;
    }
    return danger;
}

float XEnemyModel::getStrength(int x, int y)
{
    // Iterate through the enemyVector and return the strength of the enemy at the given position
    for (const auto& enemy : enemyVector)
    {
        if (enemy.x== x && enemy.y == y)
        {
            return enemy.strength;
        }
    }
    return 0.0f;
}

float XEnemyModel::isEnemyAround(int x, int y)
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

void XEnemyModel::setTileModel(const std::shared_ptr<TileModel> &newTileModel)
{
    tileModel = newTileModel;
}

std::pair<int, int> XEnemyModel::getNewPos(int move_encoded, int oldX, int oldY){

    int newX = oldX;
    int newY = oldY;

    switch(move_encoded) {
        case 0: // Move up
            newY = std::max(0, oldY - 1);
            break;
        case 1: // Move up-right
            newY = std::max(0, oldY - 1);
            newX = std::max(0, oldX - 1);
            break;
        case 2: // Move right
            newX = std::max(0, oldX - 1);
            break;
        case 3: // Move down-right
            newY = std::min(oldY + 1, world_rows - 1);
            newX = std::max(0, oldX - 1);
            break;
        case 4: // Move down
            newY = std::min(oldY + 1, world_rows-1);
            break;
        case 5: // Move down-left
            newY = std::min(oldY + 1, world_rows - 1);
            newX = std::min(oldX + 1, world_cols - 1);
            break;
        case 6: // Move left
            newX = std::min(oldX + 1, world_cols - 1);
            break;
        case 7: // Move up-left
            newY = std::max(0, oldY - 1);
            newX = std::min(oldX + 1, world_cols - 1);
            break;
        default:
            // Invalid move_encoded value
            break;
    }

    return std::make_pair(newX, newY);
}
