#ifndef TILEMODEL_H
#define TILEMODEL_H
//#include "pathfinder_class.h"
#include "world.h"
#include "node.h"
#include "pathfinder_class.h"


/**
 * @brief Represents a portal in the game.
 * Stores information about its position and whether it leads to the next level.
 */
struct Portal {
    int row=-1; /**< Row index of the portal. Default value: -1 */
    int col=-1; /**< Column index of the portal. Default value: -1 */
    bool nextLevel; /**< Indicates if the portal leads to the next level. */
};


/**
 * @brief Manages the data for the tiles in the game.
 * This class handles tile-related functionalities and information.
 */
class TileModel
{
public:

    /**
     * @brief Constructs a TileModel object with the specified number of rows and columns.
     * @param rows Number of rows in the tile grid.
     * @param cols Number of columns in the tile grid.
     */
    TileModel(int rows, int cols);

    /**
     * @brief Populates the tile map with data and initializes necessary containers.
     * @param rows Number of rows in the tile grid.
     * @param cols Number of columns in the tile grid.
     * @param tile Vector of unique pointers to Tile objects to populate the tile map.
     */
    void populateTileMap(int rows, int cols, std::vector<std::unique_ptr<Tile>> tile);

    /**
     * @brief Adds a portal to the specified position in the tile grid.
     * @param row Row index where the portal is to be added.
     * @param col Column index where the portal is to be added.
     * @param nextLevel Flag indicating if the portal leads to the next level.
     */
    void addPortal(int row, int col, bool nextLevel);

    /**
     * @brief Retrieves the tile table containing the values of the tiles in the grid.
     * @return 2D vector representing the tile table.
     */
    std::vector<std::vector<float> > getTileTable() const;

    /**
     * @brief Retrieves the number of rows in the tile grid.
     * @return Number of rows in the tile grid.
     */
    int getRows() const;

    /**
     * @brief Retrieves the number of columns in the tile grid.
     * @return Number of columns in the tile grid.
     */
    int getColumns() const;

    /**
     * @brief Retrieves the value of the tile at the specified position in the grid.
     * @param row Row index of the tile.
     * @param col Column index of the tile.
     * @return The value of the tile at the specified position.
     *         If the position is out of bounds, returns a default value of 0.0f.
     */
    float getTileValueAt(int row, int col);

    /**
     * @brief Retrieves portal information at the specified position in the grid.
     * @param row Row index to check for a portal.
     * @param col Column index to check for a portal.
     * @return An optional boolean indicating the presence of a portal and its nextLevel status.
     *         If a portal is found at the specified position, returns true or false based on nextLevel.
     *         If no portal is found, returns an empty optional.
     */
    std::optional<bool> getPortalAt(int row, int col);

    /**
     * @brief Retrieves the pair of portals present in the tile grid.
     * @return A pair of portals where first represents the first portal found
     *         and second represents the second portal found. One portal leads
     *         to the next level and one to the previous
     */
    std::pair<Portal, Portal> getPortals() const;

    /**
     * @brief Marks the tile at the specified position as visited.
     * @param row Row index of the tile.
     * @param col Column index of the tile.
     *        If the position is within the grid boundaries, marks the tile as visited.
     */
    void markTileAsVisited(int row, int col);

    /**
     * @brief Checks if the tile at the specified position has been visited.
     * @param row Row index of the tile.
     * @param col Column index of the tile.
     * @return True if the tile at the specified position has been visited, false otherwise.
     *         If the position is outside the grid boundaries, returns false.
     */
    bool isTileVisited(int row, int col) const;

    /**
     * @brief Finds a path from the starting tile to the destination tile using pathfinder.
     * @param startX X-coordinate of the starting tile.
     * @param startY Y-coordinate of the starting tile.
     * @param endX X-coordinate of the destination tile.
     * @param endY Y-coordinate of the destination tile.
     * @return A vector representing the path from the starting tile to the destination tile.
     */
    std::vector<int> findPath(int startX, int startY, int endX, int endY);

    /**
     * @brief Compares two nodes based on their values.
     * @param a First node for comparison.
     * @param b Second node for comparison.
     * @return True if the value of node 'a' is greater than the value of node 'b',
     *         or any other comparison logic relevant to the application.
     */
    bool compareNodes(const Node& a, const Node& b);

    /**
     * @brief Sets up the pathfinder using the provided start and destination tiles.
     * @param startTile Reference to the starting tile for pathfinding.
     * @param destinationTile Reference to the destination tile for pathfinding.
     *        Resets all nodes' visited status to false and initializes the pathfinder with given parameters.
     */
    void getPathfinder(Tile& startTile, Tile& destinationTile);


private:
    std::vector<std::vector<float>> tileTable; /**< Represents the values of tiles in the grid. */
    std::vector<std::vector<bool>> visitedTiles; /**< Tracks whether tiles have been visited in the grid. */
    int rows; /**< Number of rows in the tile grid. */
    int columns; /**< Number of columns in the tile grid. */
    std::pair<Portal, Portal> portals; /**< Pair of portals present in the tile grid. */
    std::vector<Node> nodes; /**< List of nodes representing elements in the grid. */
    std::unique_ptr<PathFinder<Node, Tile>> finder; /**< Unique pointer to the pathfinder used for pathfinding algorithms. */
    Comparator<Node> comp; /**< Comparator for nodes used in pathfinding algorithms. */
};

#endif // TILEMODEL_H
