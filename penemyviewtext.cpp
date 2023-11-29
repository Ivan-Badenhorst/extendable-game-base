#include "penemyviewtext.h"

PEnemyViewText::PEnemyViewText(std::shared_ptr<PEnemyModel> pem)
: penemyModel(pem)
{

}

void PEnemyViewText::update()
{

}

void PEnemyViewText::clearView()
{

}

void PEnemyViewText::setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel)
{
    penemyModel = newPenemyModel;
}
