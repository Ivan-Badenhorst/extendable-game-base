#ifndef ENEMYMODELINTERFACE_H
#define ENEMYMODELINTERFACE_H

#include "world.h"
#include <vector>

/* As we need more methods to control the game, we will add them here and all
    models that implement this interface will have to implement the new methods
*/
class EnemyModelInterface
{
public:
    virtual void addEnemy(std::shared_ptr<Enemy> enemy) = 0;
    virtual std::vector<std::shared_ptr<Enemy>> getEnemies() const = 0;
    virtual bool containsEnemy(int row, int col) = 0;
};

#endif // ENEMYMODELINTERFACE_H