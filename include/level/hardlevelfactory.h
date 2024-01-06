#ifndef HARDLEVELFACTORY_H
#define HARDLEVELFACTORY_H

#include "levelfactory.h"

/**
 * @class HardLevelFactory
 * @brief Class for a factory that creates hard game levels.
 *
 * This class inherits from the LevelFactory abstract base class and provides an implementation
 * for the method to create a world (i.e., a hard game level).
 */
class HardLevelFactory: public LevelFactory
{
public:
    /**
     * @brief Default constructor.
     */
    HardLevelFactory();

    /**
     * @brief Creates a hard world (i.e., a hard game level).
     * This is the level where the protagonist also needs to escape from XEnemies (ghost guards)
     * Number of Xenemies can be specified in this function
     * @return Shared pointer to the created Level.
     */
    std::shared_ptr<Level> createWorld() override;
};

#endif // HARDLEVELFACTORY_H
