#ifndef TEXTGAMEVIEWFACTORY_H
#define TEXTGAMEVIEWFACTORY_H


#include "gameviewfactory.h"
class TextGameViewFactory: public GameViewFactory
{
public:
    TextGameViewFactory();
    std::unique_ptr<GameView> createView(MainWindow& mainWindow) override;
};

#endif // TEXTGAMEVIEWFACTORY_H
