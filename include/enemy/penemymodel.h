#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include <memory>
#include <map>
#include <unordered_set>
#include <algorithm>
#include "enemymodelinterface.h"


struct PEnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
    float initialPoisonLevel;
    float currentPoisonLevel;
};

struct FireOnTile {
    int x;
    int y;
    int fireType;
};

/*
Cantor Pairing Function is used to hash of all coordinates.
More info on the Cantor Pairing function here : 
https://www.singlelunch.com/2018/09/26/programming-trick-cantor-pairing-perfect-hashing-of-two-integers/
*/ 


struct PEnemyCoordinateHash {
    std::size_t operator()(const PEnemyState& p) const {
        return 0.5 * (p.x + p.y) * (p.x + p.y + 1) + p.y;
    }
};

struct PEnemyCoordinateEqual {
    bool operator()(const PEnemyState& lhs, const PEnemyState& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

struct FireOnTileHash {
    std::size_t operator()(const FireOnTile& f) const {
        return 0.5 * (f.x + f.y) * (f.x + f.y + 1) + f.y;
    }
};

struct FireOnTileEqual {
    bool operator()(const FireOnTile& lhs, const FireOnTile& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};



class PEnemyModel: public EnemyModelInterface
{
public:
    PEnemyModel(int w_rows, int w_cols);
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    void drainPEnemy(int x, int y);
    std::optional<PEnemyState> getOnePEnemyState(int x, int y) const;
    std::vector<PEnemyState> getAllPEnemyStates() const;
    
    // Get all fire for a given PEnemy
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
    bool isCompleted() override;

private:
    // Unordered set of PEnemyStates
    std::unordered_set<PEnemyState, PEnemyCoordinateHash, PEnemyCoordinateEqual> enemySet; 
    /***
     * Set of fire types by tile.
     * There are 4 types of fire. The strongest one applies 100% of the damage to the player. 
     * The weakest one applies 25%.
     * */ 
    std::unordered_set<FireOnTile, FireOnTileHash, FireOnTileEqual> fireSet;

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
