#ifndef EASYLEVELFACTORY_H
#define EASYLEVELFACTORY_H

#include "levelfactory.h"

/**
 * @class EasyLevelFactory
 * @brief Class for a factory that creates medium game levels.
 *
 * This class inherits from the LevelFactory abstract base class and provides an implementation
 * for the method to create a world (i.e., a easy game level).
 */
class EasyLevelFactory: public LevelFactory
{
public:
    /**
     * @brief Default constructor.
     */
    EasyLevelFactory();

    /**
     * @brief Creates a easy world (i.e., a easy game level).
     * @return Shared pointer to the created Level.
     */
    std::shared_ptr<Level> createWorld() override;

};

#endif // EASYLEVELFACTORY_H
