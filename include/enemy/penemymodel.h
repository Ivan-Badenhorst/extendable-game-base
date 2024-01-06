/**
 * @file PEnemyModel.h
 * @brief Model for managing P-type enemies and fire effects in a game environment.
 *
 * This class extends BaseEnemyModel, providing specialized management for P-type enemies
 * and associated fire effects. It handles enemy states, attacks, poison level calculations,
 * and fire effects on tiles.
 */

#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include <memory>
#include <map>
#include <unordered_set>
#include <algorithm>
#include "baseenemymodel.h"


/**
 * @struct PEnemyState
 * @brief Structure to represent the state of a P-type enemy.
 *
 * Holds information about the enemy's position, defeat status, strength, and poison levels.
 */
struct PEnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
    float initialPoisonLevel;
    float currentPoisonLevel;
};

/**
 * @struct FireOnTile
 * @brief Structure representing fire effects on a tile.
 *
 * Holds information about the tile's coordinates and the type of fire present.
 */
struct FireOnTile {
    int x;
    int y;
    int fireType;
};

/**
 * @struct PEnemyCoordinateHash
 * @brief Hash function for PEnemyState using Cantor Pairing Function.
 *
 * Provides a hash function for PEnemyState objects.
 * 
 * Cantor Pairing Function is used to hash of all coordinates.
 * More info on the Cantor Pairing function here : 
 * https://www.singlelunch.com/2018/09/26/programming-trick-cantor-pairing-perfect-hashing-of-two-integers/
 */
struct PEnemyCoordinateHash {
    std::size_t operator()(const PEnemyState& p) const {
        return 0.5 * (p.x + p.y) * (p.x + p.y + 1) + p.y;
    }
};

/**
 * @struct PEnemyCoordinateEqual
 * @brief Equality comparison for PEnemyState objects.
 *
 * Defines equality comparison for two PEnemyState objects, based on their coordinates.
 */
struct PEnemyCoordinateEqual {
    bool operator()(const PEnemyState& lhs, const PEnemyState& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

/**
 * @struct FireOnTileHash
 * @brief Hash function for FireOnTile using Cantor Pairing Function.
 *
 * Provides a hash function for FireOnTile objects.
 */
struct FireOnTileHash {
    std::size_t operator()(const FireOnTile& f) const {
        return 0.5 * (f.x + f.y) * (f.x + f.y + 1) + f.y;
    }
};

/**
 * @struct FireOnTileEqual
 * @brief Equality comparison for FireOnTile objects.
 *
 * Defines equality comparison for two FireOnTile objects, based on their coordinates.
 */
struct FireOnTileEqual {
    bool operator()(const FireOnTile& lhs, const FireOnTile& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};


/**
 * @class PEnemyModel
 * @brief Model class for managing P-type enemies and fire effects in the game.
 *
 * Extends BaseEnemyModel to implement specific functionalities for P-type enemy
 * management such as adding, checking, attacking enemies, handling poison levels,
 * and managing fire effects on tiles.
 */
class PEnemyModel: public BaseEnemyModel
{
public:
    /**
     * @brief Constructor for PEnemyModel.
     * @param w_rows The number of rows in the game world.
     * @param w_cols The number of columns in the game world.
     */
    PEnemyModel(int w_rows, int w_cols);

    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    bool isCompleted() override;
    
    /**
     * @brief Drains poison from a P-type enemy at specified coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     */
    void drainPEnemy(int x, int y);

    /**
     * @brief Retrieves the state of a single P-type enemy at given coordinates.
     * 
     * This method fetches the state of a P-type enemy located at the specified
     * coordinates. The state includes information such as position, defeat status,
     * strength, and poison levels.
     * 
     * @param x The x-coordinate of the P-type enemy.
     * @param y The y-coordinate of the P-type enemy.
     * @return An optional containing the PEnemyState, empty if no enemy is found.
     */
    std::optional<PEnemyState> getOnePEnemyState(int x, int y) const;
    
    /**
     * @brief Retrieves the states of all P-type enemies.
     * 
     * This method fetches the states of all P-type enemies managed by the model.
     * Each state includes information such as position, defeat status, strength,
     * and poison levels.
     * 
     * @return A vector of PEnemyState objects representing all P-type enemies.
     */
    std::vector<PEnemyState> getAllPEnemyStates() const;
    
    /**
     * @brief Retrieves all fire effects caused by a P-type enemy at given coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     * @return A vector of FireOnTile representing the fire effects around the enemy.
     */
    std::vector<FireOnTile> getPEnemyFire(int x, int y) const;

    /**
     * @brief Checks if there is fire at the specified coordinates.
     *
     * This function checks if there is fire at the given coordinates (x, y) in the PEnemyModel.
     * It returns the fire type present at the specified coordinates.
     *
     * @param x The x-coordinate of the tile.
     * @param y The y-coordinate of the tile.
     * @return The fire type present at the specified coordinates.
     */
    int containsFire(int x, int y) const;
    

private:
    /**
     * @brief Set of PEnemyStates for managing P-type enemies.
     * 
     * This unordered set stores the states of P-type enemies, including their positions,
     * defeat status, strength, and poison levels. The custom hash and equality functions
     * are used for efficient access based on enemy coordinates.
     */
    std::unordered_set<PEnemyState, PEnemyCoordinateHash, PEnemyCoordinateEqual> enemySet; 

    /**
     * @brief Set of fire effects on tiles.
     * 
     * This unordered set manages the fire effects caused by P-type enemies. It stores 
     * FireOnTile objects, each representing a tile affected by fire. The set uses custom
     * hash and equality functions for efficient access. There are four types of fire, 
     * each applying different percentages of damage to the player, from 25% to 100%.
     */ 
    std::unordered_set<FireOnTile, FireOnTileHash, FireOnTileEqual> fireSet;

    /**
     * @brief Deduces the poison level of a P-type enemy at given coordinates.
     * 
     * This method reduces the poison level of a P-type enemy located at the specified
     * coordinates. It is typically called to simulate the effect of poison draining over time.
     * 
     * @param x The x-coordinate of the P-type enemy.
     * @param y The y-coordinate of the P-type enemy.
     * @return True if poison was successfully deduced, false otherwise.
     */
    bool deducePoison(int x, int y);

    /**
     * @brief Calculates the fire stage from a given poison level.
     * 
     * The poison level is a value between 0 and 100. This method divides the poison level by 25 to determine the fire stage.
     * There are 5 stages (0, 1, 2, 3, 4) and each stage represents a range of 25 poison levels:
     * - Stage 0: Poison level 0
     * - Stage 1: Poison level 1 to 24
     * - Stage 2: Poison level 25 to 49
     * - Stage 3: Poison level 50 to 74
     * - Stage 4: Poison level 75 to 100
     * 
     * @param poisonLevel The poison level of a PEnemy.
     * @return The fire stage corresponding to the given poison level.
     */
    int getFireStageFromPoisonLevel(int poisonLevel) const;

    /**
     * @brief Calculates the fire tiles around a given enemy position.
     *
     * This method calculates a square-shaped fire pattern around the enemy, with the fire intensity increasing as we get closer to the enemy.
     * The fire pattern is determined by the `drainCount`, which represents the difference between the initial and current fire stages of the enemy.
     * Each side of the square is calculated separately, and for each tile in the square, if it is within the world boundaries, a `FireOnTile` object is created and added to the `fires` vector.
     *
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     * @param drainCount The difference between the initial and current fire stages of the enemy.
     * @return A vector of `FireOnTile` objects representing the fire tiles around the enemy.
     */
    std::vector<FireOnTile> calculateFireTiles(int x, int y, int drainCount) const;
};

#endif // PENEMYMODEL_H
