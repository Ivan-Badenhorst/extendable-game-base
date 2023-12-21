#ifndef GAMEVIEWFACTORY_H
#define GAMEVIEWFACTORY_H

#include "gameview.h"

class GameViewFactory
{
public:
    GameViewFactory();
    virtual std::unique_ptr<GameView> createView(MainWindow& mainWindow) = 0;
};

#endif // GAMEVIEWFACTORY_H
