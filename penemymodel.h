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

private:
    std::map<std::pair<int, int>, std::shared_ptr<Enemy>> enemyMap; // Map to link x and y to shared pointer of enemy object
};

#endif // PENEMYMODEL_H
