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
        // // Generate a random x and y position within the world bounds
        // int newX = std::rand() % world_rows;
        // int newY = std::rand() % world_cols;

        // // Assign the new position to the enemy
        // enemy.x = newX;
        // enemy.y = newY;

        // // Check if the enemy is in the same position as the protagonist
        // if (newX == protagonistX && newY == protagonistY)
        // {
        //     danger = true;
        // }
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
