#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "commandtrienode.h"
#include "gameview.h"
#include "qlabel.h"
#include "qplaintextedit.h"

#include <QLineEdit>
#include <QKeyEvent>
class CommandLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit CommandLineEdit(QWidget *parent = nullptr): QLineEdit(parent){};
    void setCommandTrie(const std::shared_ptr<CommandTrieNode> &newCommandTrie);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::shared_ptr<CommandTrieNode> commandTrie;

};


class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;


private:
    std::shared_ptr<QPlainTextEdit> textEdit;
    std::shared_ptr<QLabel> healthLabel;
    std::shared_ptr<QLabel> healthValueLabel;
    std::shared_ptr<QLabel> energyLabel;
    std::shared_ptr<QLabel> energyValueLabel;
    std::shared_ptr<CommandLineEdit> lineEdit;
    std::shared_ptr<CommandTrieNode> commandTrie;

    void setupBasicCommands();///ADD A PUBLIC FUNCTION TO ADD MORE

};

#endif // TEXTGAMEVIEW_H
