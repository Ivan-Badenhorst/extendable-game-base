#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include <memory>
#include <unordered_set>
#include "enemymodelinterface.h"

struct EnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
};

/*
Cantor Pairing Function is used to hash of all coordinates.
More info on the Cantor Pairing function here : 
https://www.singlelunch.com/2018/09/26/programming-trick-cantor-pairing-perfect-hashing-of-two-integers/
*/

struct EnemyCoordinateHash {
    std::size_t operator()(const EnemyState& e) const {
        return 0.5 * (e.x + e.y) * (e.x + e.y + 1) + e.y;
    }
};

struct EnemyCoordinateEqual {
    bool operator()(const EnemyState& lhs, const EnemyState& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

class EnemyModel: public EnemyModelInterface
{
public:
    EnemyModel(int w_rows, int w_cols);
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    std::optional<EnemyState> getOneEnemyState(int x, int y) const;
    std::vector<EnemyState> getAllEnemyStates() const;
    

private:
    std::unordered_set<EnemyState, EnemyCoordinateHash, EnemyCoordinateEqual> enemySet; // Map to link x and y to shared pointer of enemy object
};

#endif // ENEMYMODEL_H
