/**
 * @file node.h
 * @brief Contains the Node class, representing nodes in the game environment.
 *
 * This file defines the Node class that inherits from the Tile class.
 * Nodes are used in pathfinding algorithms and represent positions in the game grid.
 */

#ifndef NODE_H
#define NODE_H
#include "world.h"

/**
 * @class Node
 * @brief Class responsible for nodes used in path finder
 *
 */
class Node: public Tile
{
public:
    /**
     * @brief Constructs a Node instance with given position and tile weight.
     *        Inherits from the Tile class and initializes a Node object with provided position and weight.
     * @param xPosition X-coordinate position of the node.
     * @param yPosition Y-coordinate position of the node.
     * @param tileWeight Weight of the node representing its value in the tile grid.
     */
    Node(int xPosition, int yPosition, float tileWeight);

    float f,g,h;/**< Float values used for pathfinding calculations in the Node. */
    bool visited{false};/**< Flag indicating if the Node has been visited during pathfinding. Default value: false */
    Node* prev {nullptr};/**< Pointer to the previous Node in the path (used in pathfinding). Initialized to nullptr */

};

#endif // NODE_H
