#ifndef ENEMYVIEWTEXT_H
#define ENEMYVIEWTEXT_H


#include "enemymodel.h"
#include "enemyviewinterface.h"
class EnemyViewText: public EnemyViewInterface
{
public:
    EnemyViewText(std::shared_ptr<EnemyModel> em);
    void update() override;
    void clearView() override;


private:
    std::shared_ptr<EnemyModel> enemyModel;
};

#endif // ENEMYVIEWTEXT_H
