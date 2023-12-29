#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include <memory>
#include <map>
#include "enemymodelinterface.h"

struct EnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
};

class EnemyModel: public EnemyModelInterface
{
public:
    EnemyModel();
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    std::optional<EnemyState> getOneEnemyState(int x, int y) const;
    std::vector<EnemyState> getAllEnemyStates() const;
    

private:
    std::map<std::pair<int, int>, EnemyState> enemyMap; // Map to link x and y to shared pointer of enemy object
};

#endif // ENEMYMODEL_H
