#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include <memory>
#include <map>
#include "enemymodelinterface.h"

struct EnemyState {
    int x;
    int y;
    bool isDefeated;
};

class EnemyModel: public EnemyModelInterface
{
public:
    EnemyModel();
    void addEnemy(std::shared_ptr<Enemy> enemy) override;
    std::vector<std::shared_ptr<Enemy>> getEnemies() const override;
    bool containsEnemy(int col, int row) override;
    bool isDefeated(int col, int row) override;
    void attackEnemy(int col, int row, int damage) override;
    EnemyState getOneEnemyState(int col, int row) const;
    std::vector<EnemyState> getAllEnemyStates() const;
    

private:
    std::map<std::pair<int, int>, std::shared_ptr<Enemy>> enemyMap; // Map to link x and y to shared pointer of enemy object
};

#endif // ENEMYMODEL_H
