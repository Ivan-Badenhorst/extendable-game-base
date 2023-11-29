#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "gameview.h"
class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;
};

#endif // TEXTGAMEVIEW_H
