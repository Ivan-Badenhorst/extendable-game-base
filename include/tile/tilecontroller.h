/**
 * @file tilecontroller.h
 * @brief Controller for managing tiles in a game environment.
 *
 * This class is responsible for controlling all tile operations
 * orchetrating movements and using energy
 */

#ifndef TILECONTROLLER_H
#define TILECONTROLLER_H

#include "tilemodel.h"
#include "tileviewgraphical.h"

/**
 * @class TileController
 * @brief Class responsible for controlling tiles in the game.
 *
 * This class manages the tile logic in the game
 */

class TileController
{
public:
    /**
     * @brief Constructs a TileController object.
     * @param tm Shared pointer to the TileModel instance.
     */
    TileController( std::shared_ptr<TileModel> tm);

    /**
     * @brief Updates the state of a tile at the specified position.
     * @param row Row index of the tile.
     * @param col Column index of the tile.
     * @param allowPortal Flag to allow portal functionality.
     * @return The value of the tile at the specified position after update.
     */
    float update(int row = 0, int col = 0, bool allowPortal = true);//later this method takes the position -> or we have reference to the protag

    /**
     * @brief Retrieves the dimensions of the tile grid.
     * @return A tuple containing the number of rows and columns in the tile grid.
     */
    std::tuple<int, int> getDimensions();

    /**
     * @brief Adds a portal to the specified position on the tile grid.
     * @param row Row index where the portal is to be added.
     * @param col Column index where the portal is to be added.
     * @param nextLevel Flag indicating if the portal leads to the next level or the previous.
     */
    void addPortal(int row, int col, bool nextLevel);

    /**
     * @brief Sets the TileView for the TileController.
     * @param newTileView Shared pointer to the TileView instance to be set.
     */
    void setTileView(const std::shared_ptr<TileView> &newTileView);

    /**
     * @brief Retrieves the energy value of the tile at the specified position.
     * @param row Row index of the tile.
     * @param col Column index of the tile.
     * @return The energy value of the tile at the specified position.
     */
    float getEnergy(int row, int col);

    /**
     * @brief Retrieves the shared pointer to the TileModel associated with the TileController.
     * @return Shared pointer to the TileModel instance.
     */
    std::shared_ptr<TileModel> getTileModel() const;

private:
    std::shared_ptr<TileView> tileView; ///< current view used to visualize the tiles
    std::shared_ptr<TileModel> tileModel; ///< model containing information on the tiles
};

#endif // TILECONTROLLER_H
