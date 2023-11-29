#ifndef PENEMYVIEWTEXT_H
#define PENEMYVIEWTEXT_H


#include "enemyviewinterface.h"
#include "penemymodel.h"
#include "penemyview.h"
class PEnemyViewText: public EnemyViewInterface, public PEnemyView
{
public:
    PEnemyViewText(std::shared_ptr<PEnemyModel> pem);
    void update() override;
    void clearView() override;


    void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel) override;

private:
    std::shared_ptr<PEnemyModel> penemyModel;
};

#endif // PENEMYVIEWTEXT_H
