/**
 * @file XEnemyModel.h
 * @brief Model for managing X-type enemies in a game environment.
 *
 * This class extends BaseEnemyModel and provides functionalities specific to managing X-type enemies,
 * including their states, movements, and interactions within the game world.
 */


#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include "baseenemymodel.h"
#include "tilemodel.h"

/**
 * @struct XEnemyState
 * @brief Structure to represent the state of an X-type enemy.
 *
 * Holds information about the enemy's position, defeat status, and strength.
 */
struct XEnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
};

/**
 * @class XEnemyModel
 * @brief Model class for managing X-type enemies.
 *
 * Extends BaseEnemyModel to implement specific functionalities for X-type
 * enemy management such as adding, moving, attacking enemies, and determining
 * their strength and proximity to the protagonist.
 */
class XEnemyModel : public BaseEnemyModel
{
public:
    /**
     * @brief Constructor for XEnemyModel.
     * @param w_rows Number of rows in the game world.
     * @param w_cols Number of columns in the game world.
     */
    XEnemyModel(int w_rows, int w_cols);

    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    bool isCompleted() override;

    /**
     * @brief Adds a specified number of X-type enemies to the game.
     * 
     * This method creates and adds a given number of X-type enemies to the model.
     * It is typically used to increase the challenge or difficulty by introducing
     * more enemies into the game environment.
     * 
     * @param amount The number of X-type enemies to add.
     */
    void addXEnemy(int amount);

    /**
     * @brief Moves the X-type enemy towards the protagonist.
     * @param protagonistX The x-coordinate of the protagonist.
     * @param protagonistY The y-coordinate of the protagonist.
     * @return True if the enemy can follow the protagonist, false otherwise.
     */
    bool follow(int protagonistX, int protagonistY);

    /**
     * @brief Gets the strength of an X-type enemy at given coordinates.
     * 
     * This method returns the strength of the X-type enemy located at the specified
     * coordinates. The strength indicates the enemy's power or health.
     * 
     * @param x The x-coordinate of the X-type enemy.
     * @param y The y-coordinate of the X-type enemy.
     * @return The strength value of the X-type enemy.
     */
    float getStrength(int x, int y);

    /**
     * @brief Checks if there is an X-type enemy around given coordinates.
     * 
     * This method determines if there is an X-type enemy in the vicinity of the specified
     * coordinates. It is typically used to check for enemy presence near the protagonist
     * or other significant game elements.
     * 
     * @param x The x-coordinate to check around.
     * @param y The y-coordinate to check around.
     * @return The strength of the nearby X-type enemy, or 0 if none is found.
     */
    float isEnemyAround(int x, int y);

    /**
     * @brief Sets the TileModel associated with the XEnemyModel.
     * 
     * This method links a TileModel to the XEnemyModel. The TileModel provides additional
     * information and functionalities related to the game world's tiles, which can be used
     * for positioning and moving the X-type enemies.
     * 
     * @param newTileModel Shared pointer to the TileModel to be associated with this enemy model.
     */
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel);
    

private:

    //std::pair<int, int> getNewPos(int move_encoded, int oldX, int oldY);
    /**
     * @brief A vector to store all the enemies.
     *
     * We use a vector because we will be iterating over the enemies very often.
     * Vectors provide efficient random access and are therefore well-suited for this use case.
     */
    std::shared_ptr<TileModel> tileModel; ///< The TileModel associated with the level for this XEnemyModel.
    std::vector<XEnemyState> enemyVector; ///< Vector to store all X-type enemies.

    /**
     * @brief Calculates the new position of an X-type enemy based on movement encoding.
     * 
     * This method determines the new position of an X-type enemy after a move,
     * based on a movement encoding scheme.
     * 
     * @param move_encoded Encoding of the move.
     * @param oldX Current x-coordinate of the enemy.
     * @param oldY Current y-coordinate of the enemy.
     * @return A pair representing the new coordinates of the enemy.
     */
    std::pair<int, int> getNewPos(int move_encoded, int oldX, int oldY); //cng
};


#endif // XENEMYMODEL_H
