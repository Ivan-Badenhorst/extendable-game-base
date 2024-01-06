#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include "level.h"
#include "prison.h"


/**
 * @class LevelFactory
 * @brief Abstract base class for a factory that creates game levels.
 *
 * This class provides an interface for a factory that creates game levels. It includes a method
 * to create a world (i.e., a game level) and a method to create basic controllers for a prison.
 */
class LevelFactory
{
public:
    
    /**
     * @brief Creates a world (i.e., a game level).
     * @return Shared pointer to the created Level.
     */
    virtual std::shared_ptr<Level> createWorld() = 0;

protected:

    /**
     * @brief Creates a tuple of shared pointers to the controllers used in the level.
     * 
     * This function creates and initializes the controllers for the tile, protagonist, health packs, and enemies in the level.
     * The controllers are stored in a tuple and returned.
     * 
     * @param p Reference to a prison object containing the necessary data for initializing the controllers.
     * @return A tuple of shared pointers to the controllers.
     */
    std::tuple<std::shared_ptr<TileController>, 
                std::shared_ptr<ProtagonistController>, 
                std::shared_ptr<HealthPackController>,
                std::shared_ptr<EnemyController>> basicControllers(Prison &p);
};

#endif // LEVELFACTORY_H
