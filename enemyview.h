#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include "enemymodel.h"
class EnemyView
{
public:
    virtual void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) = 0;
private:

};


#endif // ENEMYVIEW_H
