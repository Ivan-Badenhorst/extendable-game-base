#ifndef PENEMYVIEW_H
#define PENEMYVIEW_H
#include "penemymodel.h"
class PEnemyView
{
public:
    virtual void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newEnemyModel) = 0;
private:

};
#endif // PENEMYVIEW_H
