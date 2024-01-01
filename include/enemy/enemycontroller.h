#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
#include "enemyviewinterface.h"
#include "penemytimer.h"
#include "penemymodel.h"
#include "xenemymodel.h"

#include <memory>
#include <iostream>
#include <QPointer>
#include <QObject>
#include <QTimer>

class GameController; 




/**
 * @class EnemyController
 * @brief Class responsible for controlling enemies in the game.
 */
class EnemyController: public QObject, public std::enable_shared_from_this<EnemyController>
{
    Q_OBJECT

public:
    // Factory method to create the single instance of EnemyController.
    static std::shared_ptr<EnemyController> create(std::vector<std::unique_ptr<Enemy>> enemies, int world_rows, int world_cols);
    
    std::tuple<int, int> getWorldDimensions(int x, int y) const;

    /**
     * @brief Refreshes all graphical elements related to the enemies.
     */
    void refreshAllGraphical();
    

    /**
     * @brief Sets the enemy views for the controller.
     * @param newEnemyView The vector of enemy views to be set.
     */
    void setEnemyView(const std::vector<std::shared_ptr<EnemyViewInterface>>& newEnemyView);

    /**
     * @brief Retrieves the enemy models stored in the controller.
     * @return The vector of enemy models.
     */
    std::map<QString, std::shared_ptr<EnemyModelInterface>> getAllEnemyModels() const;

    /**
     * @brief Checks if there is an enemy at the given coordinates.
     * @param col The column to check.
     * @param row The row to check.
     * @return True if there is an enemy at the given coordinates, false otherwise.
     */
    bool containsEnemy(int x, int y) const;

    /**
     * @brief Checks if the enemy at the given coordinates has been defeated.
     * @param col The column to check.
     * @param row The row to check.
     * @return True if the enemy at the given coordinates has been defeated, false otherwise.
     */
    bool isDefeated(int x, int y) const;

    /**
     * @brief Attacks the enemy at the given coordinates.
     * @param col The column to attack.
     * @param row The row to attack.
     * @param damage The amount of damage to deal to the enemy.
     */
    void attackEnemy(int x, int y, int damage);


    void drainPEnemy(int x, int y);

    std::shared_ptr<EnemyModelInterface> getEnemyModelByType(const QString& type) const;

    void updateProtagonistPosition(int x, int y);

    void stopAttacks();

    void addXEnemy(int amount);

private:

    /**
     * @brief Default constructor for EnemyController.
     */
    EnemyController(int w_rows, int w_cols);

    // Static member for the single instance.
    //static std::shared_ptr<EnemyController> instance;
    void init(std::shared_ptr<EnemyController> ec);

    std::map<QString, std::shared_ptr<EnemyModelInterface>> enemyModels;
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews; ///< Vector of enemy views.
    std::unique_ptr<PEnemyTimer> penemytimer;

    int world_rows;
    int world_cols;

    int prot_x;
    int prot_y;

    QTimer* timer;

    GameController *gameController;

    /**
     * @brief Adds an enemy model to the controller.
     * @param em The enemy model to be added.
     */
    void addEnemyModel(std::shared_ptr<EnemyModelInterface> em);

    void checkForFire();

    void checkForEnemies();

    void checkForXEnemies();

signals:

private slots:
    void checkProtagonistPosition();
};


#endif // ENEMYCONTROLLER_H