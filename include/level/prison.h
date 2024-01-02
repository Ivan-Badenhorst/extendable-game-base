#ifndef PRISON_H
#define PRISON_H
#include "world.h"
#include <QObject>
#include <QVariant>



/**
 * @class Prison
 * @brief A class that extracts data from the World class and provides a new object for game representation.
 *
 * The Prison class is designed to allow developers to extend the representation of the game, which is a prison escape scenario. 
 * It provides functionality to add new types of enemies that inherit from the Enemy class directly into the prison.
 */
class Prison : public QObject
{
    Q_OBJECT
public:
/**
     * @brief Constructs a new Prison object.
     * @param w_tiles The tiles in the world.
     * @param w_enemies The enemies in the world.
     * @param w_healthPacks The health packs in the world.
     * @param w_rows The number of rows in the world.
     * @param w_cols The number of columns in the world.
     */
    Prison(std::vector<std::unique_ptr<Tile>> w_tiles, 
        std::vector<std::unique_ptr<Enemy>> w_enemies, 
        std::vector<std::unique_ptr<Tile>> w_healthPacks, 
        int w_rows, int w_cols);

    /**
     * @brief Gets the tiles in the prison.
     * @return The tiles in the prison.
     */
    std::vector<std::unique_ptr<Tile>> getTiles();

    /**
     * @brief Gets the enemies in the prison.
     * @return The enemies in the prison.
     */
    std::vector<std::unique_ptr<Enemy>> getEnemies();

    /**
     * @brief Gets the health packs in the prison.
     * @return The health packs in the prison.
     */
    std::vector<std::unique_ptr<Tile>> getHealthPacks();

    /**
     * @brief Gets the protagonist in the prison.
     * @return The protagonist in the prison.
     */
    std::unique_ptr<Protagonist> getProtagonist() const;

    /**
     * @brief Adds an enemy to the prison.
     * @param enemy The enemy to add.
     */
    void addEnemy(std::unique_ptr<Enemy> enemy);

    /**
     * @brief Gets the number of rows in the prison.
     * @return The number of rows in the prison.
     */
    int getRows() const {return rows;};

    /**
     * @brief Gets the number of columns in the prison.
     * @return The number of columns in the prison.
     */
    int getCols() const {return cols;};

private:
    /**
     * @brief The number of rows and columns in the prison.
     */
    int rows, cols;

    /**
     * @brief The protagonist in the prison.
     */
    std::unique_ptr<Protagonist> protagonist;

    /**
     * @brief The tiles in the prison.
     */
    std::vector<std::unique_ptr<Tile>> tiles;

    /**
     * @brief The enemies in the prison.
     */
    std::vector<std::unique_ptr<Enemy>> enemies;

    /**
     * @brief The health packs in the prison.
     */
    std::vector<std::unique_ptr<Tile>> healthPacks;
};

#endif // PRISON_H
