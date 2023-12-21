#ifndef GAMEVIEWFACTORY_H
#define GAMEVIEWFACTORY_H

#include "gameview.h"

class GameViewFactory
{
public:
    GameViewFactory();
    virtual std::shared_ptr<GameView> createView() = 0;
};

#endif // GAMEVIEWFACTORY_H
