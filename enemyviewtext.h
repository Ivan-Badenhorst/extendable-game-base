#ifndef ENEMYVIEWTEXT_H
#define ENEMYVIEWTEXT_H


#include "enemymodel.h"
#include "enemyview.h"
#include "enemyviewinterface.h"
class EnemyViewText: public EnemyViewInterface, public EnemyView
{
public:
    EnemyViewText();
    void update() override;
    void clearView() override;
    void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) override;

private:
    std::shared_ptr<EnemyModel> enemyModel;

};

#endif // ENEMYVIEWTEXT_H
