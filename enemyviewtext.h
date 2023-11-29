#ifndef ENEMYVIEWTEXT_H
#define ENEMYVIEWTEXT_H


#include "enemyviewinterface.h"
class EnemyViewText: public EnemyViewInterface
{
public:
    EnemyViewText();
    void update() override;
    void clearView() override;
};

#endif // ENEMYVIEWTEXT_H
