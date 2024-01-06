/**
 * @file EnemyController.h
 * @brief Controller for managing enemies in a game environment.
 *
 * This class is responsible for controlling all enemy-related operations
 * in a game, such as updating positions, checking for collisions, and managing
 * enemy behavior. It interacts with both the enemy models and views.
 */

#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
#include "baseenemyview.h"
#include "penemytimer.h"
#include "penemymodel.h"
#include "xenemymodel.h"

#include <memory>
#include <iostream>
#include <QPointer>
#include <QObject>
#include <QTimer>


constexpr int XENEMY_TIMER_INTERVAL = 2000;
constexpr int ENEMY_TIMER_INTERVAL = 2000;


class GameController; 




/**
 * @class EnemyController
 * @brief Class responsible for controlling enemies in the game.
 *
 * This class manages the enemy logic in the game. It keeps track of enemy
 * models and views and performs operations like moving enemies, checking
 * for collisions, and updating enemy states.
 */
class EnemyController: public QObject, public std::enable_shared_from_this<EnemyController>
{
    Q_OBJECT

public:
    /**
     * @brief Factory method to create the single instance of EnemyController.
     * @param enemies Vector of unique pointers to enemies.
     * @param world_rows Number of rows in the game world.
     * @param world_cols Number of columns in the game world.
     * @return Shared pointer to the created EnemyController instance.
     */
    static std::shared_ptr<EnemyController> create(std::vector<std::unique_ptr<Enemy>> enemies, int world_rows, int world_cols);
    
    /**
     * @brief Gets the dimensions of the world.
     * @param x The x-coordinate in the world.
     * @param y The y-coordinate in the world.
     * @return A tuple containing the world's dimensions.
     */
    std::tuple<int, int> getWorldDimensions(int x, int y) const;

    /**
     * @brief Refreshes all graphical elements related to the enemies.
     */
    void refreshAll();
    

    /**
     * @brief Sets the enemy views for the controller.
     * @param newEnemyView The vector of enemy views to be set.
     */
    void setEnemyView(const std::vector<std::shared_ptr<BaseEnemyView>>& newEnemyView);

    /**
     * @brief Retrieves the enemy models stored in the controller.
     * @return Map of QString keys to shared pointers of BaseEnemyModel instances.
     */
    std::map<QString, std::shared_ptr<BaseEnemyModel>> getAllEnemyModels() const;

    /**
     * @brief Checks if there is an enemy at the given coordinates.
     * @param x The x-coordinate to check.
     * @param y The y-coordinate to check.
     * @return True if there is an enemy at the given coordinates, false otherwise.
     */
    bool containsEnemy(int x, int y) const;

    /**
     * @brief Checks if the enemy at the given coordinates has been defeated.
     * @param x The x-coordinate to check.
     * @param y The y-coordinate to check.
     * @return True if the enemy at the given coordinates has been defeated, false otherwise.
     */
    bool isDefeated(int x, int y) const;

    /**
     * @brief Attacks the enemy at the given coordinates.
     * @param x The x-coordinate where the enemy is located.
     * @param y The y-coordinate where the enemy is located.
     * @param damage The amount of damage to deal to the enemy.
     */
    void attackEnemy(int x, int y, int damage);

    /**
     * @brief Drains the poison of a P-type enemy at given coordinates.
     * @param x The x-coordinate of the enemy.
     * @param y The y-coordinate of the enemy.
     */
    void drainPEnemy(int x, int y);

    /**
     * @brief Retrieves an enemy model by its type.
     * @param type The type of the enemy as a QString.
     * @return Shared pointer to the corresponding BaseEnemyModel.
     */
    std::shared_ptr<BaseEnemyModel> getEnemyModelByType(const QString& type) const;

    /**
     * @brief Updates the position of the protagonist in the controller.
     * @param x The new x-coordinate of the protagonist.
     * @param y The new y-coordinate of the protagonist.
     */
    void updateProtagonistPosition(int x, int y);

    /**
     * @brief Adds a specified number of X-type enemies to the game.
     * @param amount The number of X-type enemies to add.
     */
    void addXEnemy(int amount);

    /**
     * @brief Sets the tile model for the enemy controller.
     * @param newTileModel Shared pointer to the new TileModel to set.
     */
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel);
    
    /**
     * @brief Checks if the current level is complete.
     * @return True if the level is complete, false otherwise.
     */
    bool checkLevelComplete();

    /**
     * @brief Freezes all enemy movements and actions.
     */
    void freezeEnemies();

    /**
     * @brief Unfreezes all enemy movements and actions.
     */
    void unfreezeEnemies();

private:

    /**
     * @brief Private constructor for EnemyController.
     * @param w_rows The number of rows in the game world.
     * @param w_cols The number of columns in the game world.
     */
    EnemyController(int w_rows, int w_cols);

    /**
     * @brief Initializes the EnemyController instance.
     * @param ec Shared pointer to the EnemyController instance.
     */
    void init(std::shared_ptr<EnemyController> ec);

    std::map<QString, std::shared_ptr<BaseEnemyModel>> enemyModels; ///< Map of enemy models.
    std::vector<std::shared_ptr<BaseEnemyView>> enemyViews; ///< Vector of enemy views.
    std::unique_ptr<PEnemyTimer> penemytimer; ///< Timers for P-type enemies.

    int world_rows; ///< The number of rows in the game world.
    int world_cols; ///< The number of columns in the game world.

    int prot_x; ///< The x-coordinate of the protagonist.
    int prot_y; ///< The y-coordinate of the protagonist.

    QTimer* DamageTimer; ///< Timer for managing damage to enemies.
    QTimer* XEnemyTimer; ///< Timer for managing X-type enemies.

    GameController *gameController; ///< Pointer to the game controller.

    /**
     * @brief Adds an enemy model to the controller.
     * @param em Shared pointer to the enemy model to be added.
     */
    void addEnemyModel(std::shared_ptr<BaseEnemyModel> em);

    /**
     * @brief Checks for fire-related actions in the game.
     */
    void checkForFire();

    /**
     * @brief Checks for enemy-related actions in the game.
     */
    void checkForEnemies();

    /**
     * @brief Checks for X-type enemy actions in the game.
     */
    void checkForXEnemies();


signals:

private slots:
    /**
     * @brief Slot for checking the protagonist's position.
     */
    void checkProtagonistPosition();

    /**
     * @brief Slot for moving X-type enemies.
     */
    void moveXEnemy();
};


#endif // ENEMYCONTROLLER_H
