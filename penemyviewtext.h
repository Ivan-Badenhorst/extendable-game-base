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


    void setPenemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel);

private:
    std::shared_ptr<PEnemyModel> penemyModel;
};

#endif // PENEMYVIEWTEXT_H
