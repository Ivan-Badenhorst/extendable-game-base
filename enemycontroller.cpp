#include "enemycontroller.h"

EnemyController::EnemyController()
{
    // Models are added in the factory using the addEnemyModel method
}

void EnemyController::addEnemyModel(std::shared_ptr<EnemyModelInterface> em)
{
    // Add the model to the vector
    enemyModels.push_back(em);
}
