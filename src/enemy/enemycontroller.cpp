#include "enemycontroller.h"
#include "penemymodel.h"
#include "gamecontroller.h"
#include <QCoreApplication>


EnemyController::EnemyController(int w_rows, int w_cols)
{
    world_rows = w_rows;
    world_cols = w_cols;
    // Initialize the timer
    DamageTimer = new QTimer(this);
    XEnemyTimer = new QTimer(this);

    connect(XEnemyTimer, &QTimer::timeout, this, &EnemyController::moveXEnemy);
    // Connect the timer's timeout signal to the checkProtagonistPosition method
    connect(DamageTimer, &QTimer::timeout, this, &EnemyController::checkProtagonistPosition);
    // Start the timer to trigger every second
    DamageTimer->start(ENEMY_TIMER_INTERVAL);
    XEnemyTimer->start(XENEMY_TIMER_INTERVAL);
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
    auto xem = std::make_shared<XEnemyModel>(world_rows, world_cols);

    // Add your models to the controller here
    instance->addEnemyModel(em);
    instance->addEnemyModel(pem);
    instance->addEnemyModel(xem);

    for (auto& enemy : enemies) {
        QString enemyType = enemy->property("enemyType").toString();
        auto model = instance->enemyModels.find(enemyType);
        if (model != instance->enemyModels.end()) {
            model->second->addEnemy(std::move(enemy));
        } 
    }

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



void EnemyController::refreshAll()
{
    // Iterate through the enemyGraphicalViews vector and refresh each view
    for (auto const &x : enemyViews)
    {
        x->render();
    }
}



void EnemyController::addEnemyModel(std::shared_ptr<BaseEnemyModel> em)
{
    QString enemyType = QString::fromStdString(em->getEnemyType());
    enemyModels[enemyType] = em;
}



void EnemyController::setEnemyView(const std::vector<std::shared_ptr<BaseEnemyView>> &newEnemyView)
{
    enemyViews = newEnemyView;
}



std::map<QString, std::shared_ptr<BaseEnemyModel>> EnemyController::getAllEnemyModels() const

{
    return enemyModels;
}



bool EnemyController::containsEnemy(int x, int y) const
{
    // Iterate through the enemyModels map and check if any of the models contain the given coordinates
    for (const auto& pair : enemyModels) {
        if (pair.second->containsEnemy(x, y)) {
            return true;
        }
    }
    return false;
}



bool EnemyController::isDefeated(int x, int y) const
{
    // Iterate through the enemyModels map and check if any of the models contain the given coordinates
    for (const auto& pair : enemyModels) {
        if (pair.second->containsEnemy(x, y)) {
            return pair.second->isDefeated(x, y);
        }
    }
    return false;
}



void EnemyController::attackEnemy(int x, int y, int damage)
{
    // Iterate through the enemyModels map and check if any of the models contain the given coordinates
    for (const auto& pair : enemyModels) {
        if (pair.second->containsEnemy(x, y)) {
            pair.second->attackEnemy(x, y, damage);
            auto etype = pair.second->getEnemyType();
            for (auto const &ev : enemyViews) {
                if (ev->getEnemyType() == etype) {
                    ev->render(x, y);
                    break;
                }
            }
            if (etype == "PEnemy") {
                penemytimer->addEnemy(x, y);
            }
            break;
        }
    }
}



void EnemyController::drainPEnemy(int x, int y)
{
    auto model = enemyModels.find("PEnemy");
    if (model != enemyModels.end()) {
        if (auto PEnemyM = std::dynamic_pointer_cast<PEnemyModel>(model->second)) {
            PEnemyM->drainPEnemy(x, y);
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

std::shared_ptr<BaseEnemyModel> EnemyController::getEnemyModelByType(const QString& type) const
{
    auto model = enemyModels.find(type);
    if (model != enemyModels.end()) {
        return model->second;
    }
    return nullptr;
}



void EnemyController::checkForFire()
{
    auto pEnemyModel = getEnemyModelByType(QString("PEnemy"));
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
    auto Model = getEnemyModelByType(QString("Enemy"));
    auto enModel = std::dynamic_pointer_cast<EnemyModel>(Model);
    auto damage = enModel->isEnemyAround(prot_x, prot_y);
    if (damage > 0) {
        gameController->damageToProtagonist(damage);
    }
}

void EnemyController::checkForXEnemies()
{
    auto Model = getEnemyModelByType(QString("XEnemy"));
    auto xenModel = std::dynamic_pointer_cast<XEnemyModel>(Model);
    auto damage = xenModel->isEnemyAround(prot_x, prot_y);
    if (damage > 0) {
        gameController->damageToProtagonist(damage);
    }
}

bool EnemyController::checkLevelComplete()
{
    auto enemyModels = getAllEnemyModels();
    for (auto& pair : enemyModels) {
        auto& enemyModel = pair.second;
        if (!enemyModel->isCompleted()) {
            return false;
        }
    }

    return true;
}



void EnemyController::freezeEnemies()
{
    DamageTimer->stop();
    XEnemyTimer->stop();
}



void EnemyController::unfreezeEnemies()
{
    DamageTimer->start(ENEMY_TIMER_INTERVAL);
    XEnemyTimer->start(XENEMY_TIMER_INTERVAL);
}



void EnemyController::moveXEnemy()
{
    // Tell the enemies to follow the protagonist
    auto Model = getEnemyModelByType(QString("XEnemy"));
    auto xenModel = std::dynamic_pointer_cast<XEnemyModel>(Model);
    gameController->warnProtagonist(xenModel->follow(prot_x, prot_y));
}

void EnemyController::updateProtagonistPosition(int x, int y)
{
    // We first update the protagonist position
    prot_x = x;
    prot_y = y;

    // If he is on a tile that has fire, he will get one damage by default
    checkForFire();

}




void EnemyController::addXEnemy(int amount)
{
    auto Model = getEnemyModelByType(QString("XEnemy"));
    auto xEnemyModel = std::dynamic_pointer_cast<XEnemyModel>(Model);
    xEnemyModel->addXEnemy(amount);
}

void EnemyController::setTileModel(const std::shared_ptr<TileModel> &newTileModel)
{
    auto Model = getEnemyModelByType(QString("XEnemy"));
    auto xEnemyModel = std::dynamic_pointer_cast<XEnemyModel>(Model);
    xEnemyModel->setTileModel(newTileModel);
}



void EnemyController::checkProtagonistPosition()
{   
    // Check if the protagonist is on a tile that has fire
    checkForFire();

    // Check if there are enemies around the protagonist
    checkForEnemies();

    // Check if there are X enemies around the protagonist
    checkForXEnemies();
}
