#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

class EnemyViewInterface
{
public:
    virtual void update() = 0;
    //virtual void update(int row, int col,  bool used = true) = 0;
};

#endif // ENEMYVIEWINTERFACE_H
