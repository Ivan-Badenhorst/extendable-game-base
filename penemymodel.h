#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include <memory>
#include <map>
#include "enemymodelinterface.h"

class PEnemyModel: public EnemyModelInterface
{
public:
    PEnemyModel();
    void addEnemy(std::shared_ptr<Enemy> enemy) override;
    std::vector<std::shared_ptr<Enemy>> getEnemies() const override;
    bool containsEnemy(int row, int col) override;
    bool isDefeated(int row, int col) override;
    void attackEnemy(int row, int col, int damage) override;
    void drainPEnemy(int row, int col);

private:
    // Map to link x and y to shared pointer of enemy object
    std::map<std::pair<int, int>, std::shared_ptr<Enemy>> enemyMap; 
    // Map of fire types by tile
    std::map<std::pair<int, int>, int> fireMap; 
    // To keep track of how many times a penemy has been drained
    std::map<std::pair<int, int>, int> drained; 
    // Get the fire state for a given PEnemy from his poison level
    int calculateFireState(float poisonLevel) const;

    float getPoisonLevel(int row, int col) const;
    
};

#endif // PENEMYMODEL_H
