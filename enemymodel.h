#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include <memory>
#include <map>
#include "enemymodelinterface.h"



class EnemyModel: public EnemyModelInterface
{
public:
    EnemyModel();
    void addEnemy(std::shared_ptr<Enemy> enemy) override;
    std::vector<std::shared_ptr<Enemy>> getEnemies() const override;
    bool containsEnemy(int col, int row) override;

private:
    std::map<std::pair<int, int>, std::shared_ptr<Enemy>> enemyMap; // Map to link x and y to shared pointer of enemy object
};

#endif // ENEMYMODEL_H
