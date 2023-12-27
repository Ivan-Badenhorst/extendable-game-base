#include "enemycontroller.h"
#include "penemymodel.h"


EnemyController::EnemyController()
{
    // Models are added in the factory using the addEnemyModel method
}

void EnemyController::init()
{
    penemytimer = std::make_unique<PEnemyTimer>(shared_from_this());
}

void EnemyController::refreshAllGraphical()
{
    // Iterate through the enemyGraphicalViews vector and refresh each view
    for (auto const &x : enemyViews)
    {
        x->render();
    }
}

void EnemyController::addEnemyModel(std::shared_ptr<EnemyModelInterface> em)
{
    // Add the model to the vector
    enemyModels.push_back(em);
}

void EnemyController::setEnemyView(const std::vector<std::shared_ptr<EnemyViewInterface>> &newEnemyView)
{
    enemyViews = newEnemyView;
}


std::vector<std::shared_ptr<EnemyModelInterface> > EnemyController::getAllEnemyModels() const

{
    return enemyModels;
}

bool EnemyController::containsEnemy(int x, int y) const
{
    // Iterate through the enemyModels vector and check if any of the models contain the given coordinates
    for (auto const &em : enemyModels)
    {
        if (em->containsEnemy(x, y))
        {
            return true;
        }
    }
    return false;
}

bool EnemyController::isDefeated(int x, int y) const
{
    // Iterate through the enemyModels vector and check if any of the models contain the given coordinates
    for (auto const &em : enemyModels)
    {
        if (em->containsEnemy(x, y))
        {
            return em->isDefeated(x, y);
        }
    }
    return false;
}

void EnemyController::attackEnemy(int x, int y, int damage)
{
    // Iterate through the enemyModels vector and check if any of the models contain the given coordinates
    for (auto const &em : enemyModels)
    {
        if (em->containsEnemy(x, y))
        {
            em->attackEnemy(x, y, damage);
            auto etype = em->getEnemyType();
            if (etype == "PEnemy")
            {
                penemytimer->addEnemy(x, y);
                for (auto const &ev : enemyViews)
                {
                    if (ev->getEnemyType() == "PEnemy")
                    {
                        ev->render(x, y);
                        break;
                    }
                }
            }
            else if (etype == "Enemy")
            {
                for (auto const &ev : enemyViews)
                {
                    if (ev->getEnemyType() == "Enemy")
                    {
                        ev->render(x, y);
                        break;
                    }
                }
            }
        }
    }
}

void EnemyController::drainPEnemy(int x, int y)
{
    std::cout << "Draining Penemy : " << x << "," << y << std::endl;
}

std::shared_ptr<EnemyModel> EnemyController::getEnemyModel() const
{
    for (auto& m : enemyModels)
    {
        if (m->getEnemyType() == "Enemy")
        {
            if (auto EnemyM = std::dynamic_pointer_cast<EnemyModel>(m))
            {
                return EnemyM;
            }
        }
    }
    return nullptr;
}


std::shared_ptr<PEnemyModel> EnemyController::getPEnemyModel() const
{
    for (auto& m : enemyModels)
    {
        if (m->getEnemyType() == "PEnemy")
        {
            if (auto pEnemyM = std::dynamic_pointer_cast<PEnemyModel>(m))
            {
                return pEnemyM;
            }
        }
    }
    return nullptr;
}