#ifndef PENEMYVIEWTEXT_H
#define PENEMYVIEWTEXT_H


#include "enemyviewinterface.h"
#include "penemymodel.h"
class PEnemyViewText: public EnemyViewInterface
{
public:
    PEnemyViewText(std::shared_ptr<PEnemyModel> pem);
    void update() override;
    void clearView() override;


private:
    std::shared_ptr<PEnemyModel> penemyModel;
};

#endif // PENEMYVIEWTEXT_H
