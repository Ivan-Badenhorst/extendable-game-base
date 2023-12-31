#include "enemycontroller.h"
#include "penemymodel.h"
#include "gamecontroller.h"
#include <QCoreApplication>


EnemyController::EnemyController(int w_rows, int w_cols)
{
    world_rows = w_rows;
    world_cols = w_cols;
    // Initialize the timer
    timer = new QTimer(this);
    // Connect the timer's timeout signal to the checkProtagonistPosition method
    connect(timer, &QTimer::timeout, this, &EnemyController::checkProtagonistPosition);
    // Start the timer to trigger every second
    timer->start(2000);
    gameController = GameController::getInstance();
}

void EnemyController::init(std::shared_ptr<EnemyController> ec)
{
    penemytimer = std::make_unique<PEnemyTimer>(ec);
}


std::shared_ptr<EnemyController> EnemyController::create(std::vector<std::unique_ptr<Enemy>> enemies, int world_rows, int world_cols)
{
    // We first create an instance of the controller
    std::shared_ptr<EnemyController> instance(new EnemyController(world_rows, world_cols));

    // We then call the init method to set up the penemytimer
    instance->init(instance);

    //Create your enemy models here
    auto em = std::make_shared<EnemyModel>(world_rows, world_cols);
    auto pem = std::make_shared<PEnemyModel>(world_rows, world_cols);

    for (auto& enemy : enemies) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pem->addEnemy(std::move(enemy));
        } else {
            em->addEnemy(std::move(enemy));
        }
    }

    // Add your models to the controller here
    instance->addEnemyModel(em);
    instance->addEnemyModel(pem);

    /* Note about the views
    Remember that the views are handled by the game controller. 
    You should set them up there to comply with the game logic.
    Your views should provide a method to set the enemy model if you require it.
    */ 
    
    return instance;
}

std::tuple<int, int> EnemyController::getWorldDimensions(int x, int y) const
{
    return std::make_tuple(world_rows, world_cols);
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
    for (auto& m : enemyModels)
    {
        if (m->getEnemyType() == "PEnemy")
        {
            if (auto PEnemyM = std::dynamic_pointer_cast<PEnemyModel>(m))
            {
                PEnemyM->drainPEnemy(x, y);
                break;
            }
        }
    }

    for (auto const &ev : enemyViews)
    {
        if (ev->getEnemyType() == "PEnemy")
        {
            ev->render(x, y);
            break;
        }
    }
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

void EnemyController::checkForFire()
{
    auto pEnemyModel = getPEnemyModel();
    if (pEnemyModel) {
        auto pEnemy = std::dynamic_pointer_cast<PEnemyModel>(pEnemyModel);
        if (auto fireType = pEnemy->containsFire(prot_x, prot_y)) {
            switch(fireType) {
                case 1:
                    gameController->damageToProtagonist(25);
                    break;
                case 2:
                    gameController->damageToProtagonist(50);
                    break;
                case 3:
                    gameController->damageToProtagonist(75);
                    break;
                case 4:
                    gameController->damageToProtagonist(100);
                    break;
                default:
                    break;
            }
        }
    }
}

void EnemyController::checkForEnemies()
{
    auto enemyModel = getEnemyModel();
    auto damage = enemyModel->isEnemyAround(prot_x, prot_y);
    if (damage > 0) {
        gameController->damageToProtagonist(damage);
    }
}

void EnemyController::updateProtagonistPosition(int x, int y)
{
    // We first update the protagonist position
    prot_x = x;
    prot_y = y;

    // If he is on a tile that has fire, he will get one damage by default
    checkForFire();
}

void EnemyController::stopAttacks()
{
    timer->stop();
}

void EnemyController::checkProtagonistPosition()
{   
    // Check if the protagonist is on a tile that has fire
    checkForFire();

    // Check if there are enemies around the protagonist
    checkForEnemies();
}
