#ifndef TEXTGAMEVIEWFACTORY_H
#define TEXTGAMEVIEWFACTORY_H


#include "gameviewfactory.h"
class TextGameViewFactory: public GameViewFactory
{
public:
    TextGameViewFactory();
    std::shared_ptr<GameView> createView() override;
};

#endif // TEXTGAMEVIEWFACTORY_H
