#ifndef NODE_H
#define NODE_H
#include "world.h"

class Node: public Tile
{
public:
    Node(int xPosition, int yPosition, float tileWeight);


    //attr:
    float f,g,h;
    bool visited{false};
    Node* prev {nullptr};

};

#endif // NODE_H
