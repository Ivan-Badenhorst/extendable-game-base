#ifndef PENEMYVIEWTEXT_H
#define PENEMYVIEWTEXT_H


#include "enemyviewinterface.h"
#include "penemymodel.h"
#include "penemyview.h"
class PEnemyViewText: public EnemyViewInterface, public PEnemyView
{
public:
    PEnemyViewText();
    void update() override;
    void clearView() override;
    void update(int row, int col,  bool defeated) override;


    void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel) override;

private:
    std::shared_ptr<PEnemyModel> penemyModel;
};

#endif // PENEMYVIEWTEXT_H
