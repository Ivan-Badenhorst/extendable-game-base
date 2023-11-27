#include "enemycontroller.h"

EnemyController::EnemyController()
{
    // Models are added in the factory using the addEnemyModel method
}

void EnemyController::refreshAllGraphical()
{
    // Iterate through the enemyGraphicalViews vector and refresh each view
    for (auto const& x : enemyViews)
    {
        x->update();
    }
}

void EnemyController::addEnemyModel(std::shared_ptr<EnemyModelInterface> em)
{
    // Add the model to the vector
    enemyModels.push_back(em);
}

void EnemyController::setEnemyView(const std::vector<std::shared_ptr<EnemyViewInterface> > &newEnemyView)
{
    enemyViews = newEnemyView;
}

std::vector<std::shared_ptr<EnemyModelInterface> > EnemyController::getEnemyModels() const
{
    return enemyModels;
}
