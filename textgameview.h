#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "gameview.h"
#include "qplaintextedit.h"
class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;

private:
    std::shared_ptr<QPlainTextEdit> textEdit;
};

#endif // TEXTGAMEVIEW_H
