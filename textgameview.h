#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "gameview.h"
#include "qlabel.h"
#include "qplaintextedit.h"
class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;

//    void updateHealthDisplay(int currentHealth, int maxHealth);
private:
    std::shared_ptr<QPlainTextEdit> textEdit;
    std::shared_ptr<QLabel> healthLabel;
    std::shared_ptr<QLabel> healthValueLabel;
};

#endif // TEXTGAMEVIEW_H
