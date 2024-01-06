#ifndef MEDIUMLEVELFACTORY_H
#define MEDIUMLEVELFACTORY_H

#include "levelfactory.h"

/**
 * @class MediumLevelFactory
 * @brief Class for a factory that creates medium game levels.
 *
 * This class inherits from the LevelFactory abstract base class and provides an implementation
 * for the method to create a world (i.e., a medium game level).
 */
class MediumLevelFactory: public LevelFactory
{
public:
    /**
     * @brief Default constructor.
     */
    MediumLevelFactory();

    /**
     * @brief Creates a medium world (i.e., a medium game level).
     * @return Shared pointer to the created Level.
     */
    std::shared_ptr<Level> createWorld() override;
};

#endif // MEDIUMLEVELFACTORY_H
