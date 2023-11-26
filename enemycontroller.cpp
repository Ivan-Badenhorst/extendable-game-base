#include "enemycontroller.h"

EnemyController::EnemyController()
{
    // Models are added in the factory using the addEnemyModel method
}

void EnemyController::refreshAllGraphical()
{
    // Iterate through the enemyGraphicalViews vector and refresh each view
    for (auto const& x : enemyGraphicalViews)
    {
        x->update();
    }
}

void EnemyController::addEnemyModel(std::shared_ptr<EnemyModelInterface> em)
{
    // Add the model to the vector
    enemyModels.push_back(em);
}

void EnemyController::addEnemyGraphicalView(std::shared_ptr<EnemyViewInterface> ev)
{
    // Add the view to the vector
    enemyGraphicalViews.push_back(ev);
}
