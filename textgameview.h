#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "commandtrienode.h"
#include "gameview.h"
#include "qplaintextedit.h"

#include <QLineEdit>
#include <QKeyEvent>
class CommandLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit CommandLineEdit(QWidget *parent = nullptr): QLineEdit(parent){};

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;


private:
    std::shared_ptr<QPlainTextEdit> textEdit;
    std::shared_ptr<CommandLineEdit> lineEdit;
    std::shared_ptr<CommandTrieNode> commandTrie;

    void setupBasicCommands();///ADD A PUBLIC FUNCTION TO ADD MORE
};

#endif // TEXTGAMEVIEW_H
