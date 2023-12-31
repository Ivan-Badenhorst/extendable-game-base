#ifndef GRAPHICGAMEVIEWFACTORY_H
#define GRAPHICGAMEVIEWFACTORY_H

#include "gameviewfactory.h"
class GraphicGameViewFactory: public GameViewFactory
{
public:
    GraphicGameViewFactory();
    std::unique_ptr<GameView> createView(MainWindow& mainWindow) override;
};

#endif // GRAPHICGAMEVIEWFACTORY_H
