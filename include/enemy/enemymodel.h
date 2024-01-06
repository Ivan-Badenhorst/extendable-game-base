/**
 * @file EnemyModel.h
 * @brief Model for managing enemy states and behaviors in a game environment.
 *
 * This class extends BaseEnemyModel and provides concrete implementation
 * for managing enemies, including their positions, states, and interactions.
 */

#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include <memory>
#include <unordered_set>
#include "baseenemymodel.h"

/**
 * @struct EnemyState
 * @brief Structure to represent the state of an enemy.
 *
 * Holds information about the enemy's position, defeat status, and strength.
 */
struct EnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
};

/**
 * @struct EnemyCoordinateHash
 * @brief Hash function for EnemyState using Cantor Pairing Function.
 *
 * Provides a hash function for EnemyState objects, particularly useful for
 * hashing coordinates.
 * 
 * Cantor Pairing Function is used to hash of all coordinates.
 * More info on the Cantor Pairing function here : 
 * https://www.singlelunch.com/2018/09/26/programming-trick-cantor-pairing-perfect-hashing-of-two-integers/
 */
struct EnemyCoordinateHash {
    std::size_t operator()(const EnemyState& e) const {
        return 0.5 * (e.x + e.y) * (e.x + e.y + 1) + e.y;
    }
};

/**
 * @struct EnemyCoordinateEqual
 * @brief Equality comparison for EnemyState objects.
 *
 * Defines equality comparison for two EnemyState objects, based on their
 * coordinates.
 */
struct EnemyCoordinateEqual {
    bool operator()(const EnemyState& lhs, const EnemyState& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

/**
 * @class EnemyModel
 * @brief Model class for managing enemies.
 *
 * Extends BaseEnemyModel to implement specific functionalities for enemy
 * management such as adding, checking, attacking enemies and retrieving
 * their states.
 */
class EnemyModel: public BaseEnemyModel
{
public:
    /**
     * @brief Constructor for EnemyModel.
     * @param w_rows The number of rows in the game world.
     * @param w_cols The number of columns in the game world.
     */
    EnemyModel(int w_rows, int w_cols);
    
    
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    bool isCompleted() override;

    /**
     * @brief Gets the state of a single enemy at given coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     * @return An optional containing the enemy state, empty if no enemy is found.
     */
    std::optional<EnemyState> getOneEnemyState(int x, int y) const;
    
    /**
     * @brief Retrieves the states of all enemies.
     * @return A vector of EnemyState objects representing all enemies.
     */
    std::vector<EnemyState> getAllEnemyStates() const;
    
    /**
     * @brief Gets the strength of an enemy at given coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     * @return The strength value of the enemy.
     */
    float getStrength(int x, int y) const;
    
    /**
     * @brief Checks if there is an enemy around given coordinates.
     * @param x The x-coordinate to check around.
     * @param y The y-coordinate to check around.
     * @return The strength of the nearby enemy, or 0 if none is found.
     */
    float isEnemyAround(int x, int y);
    
    
    
    

private:
    std::unordered_set<EnemyState, EnemyCoordinateHash, EnemyCoordinateEqual> enemySet; /**< Set for managing enemy states. */
};

#endif // ENEMYMODEL_H
