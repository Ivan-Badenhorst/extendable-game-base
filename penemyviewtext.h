#ifndef PENEMYVIEWTEXT_H
#define PENEMYVIEWTEXT_H


#include "enemyviewinterface.h"
class PEnemyViewText: public EnemyViewInterface
{
public:
    PEnemyViewText();
    void update() override;
    void clearView() override;
};

#endif // PENEMYVIEWTEXT_H
