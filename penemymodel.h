#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include <memory>
#include <map>
#include <unordered_set>
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
    PEnemyModel();
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int row, int col) override;
    bool isDefeated(int row, int col) override;
    void attackEnemy(int row, int col, int damage) override;
    void drainPEnemy(int row, int col);
    std::optional<PEnemyState> getOnePEnemyState(int x, int y) const;
    std::vector<PEnemyState> getAllPEnemyStates() const;
    // Get all fire to render for a given PEnemy
    

    std::vector<FireOnTile> getPEnemyFireToRender(int x, int y) const;

    private:
        // Unordered set of PEnemyStates
        std::unordered_set<PEnemyState, PEnemyCoordinateHash, PEnemyCoordinateEqual> enemySet; 
        /***
         * Set of fire types by tile.
         * There are 4 types of fire. The strongest one applies 100% of the strength of the PEnemy
         * as damage to the player. The weakest one applies 25% of the strength of the PEnemy as damage
         * */ 
        std::unordered_set<FireOnTile, FireOnTileHash, FireOnTileEqual> fireSet; 
        // To keep track of how many times a penemy has been drained
        // Get the fire state for a given PEnemy from his poison level
        int calculateFireState(float poisonLevel) const;

    float getPoisonLevel(int row, int col) const;
    
};

#endif // PENEMYMODEL_H
