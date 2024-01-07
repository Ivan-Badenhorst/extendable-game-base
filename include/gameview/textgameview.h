/**
 * @file textgameview.h
 * @brief Defines the TextGameView class.
 * Manages the text-based game view by inheriting from GameView. And defines all
 * needed components
 */

#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "commandtrienode.h"
#include "gameview.h"
#include "qlabel.h"
#include "qplaintextedit.h"

#include <QLineEdit>
#include <QKeyEvent>

/**
 * @class CommandLineEdit
 * @brief Custom QLineEdit class managing commands and interactions.
 */
class CommandLineEdit : public QLineEdit {
    Q_OBJECT
public:

    /**
     * @brief Constructor for CommandLineEdit.
     * @param parent The parent widget.
     */
    explicit CommandLineEdit(QWidget *parent = nullptr): QLineEdit(parent){};

    /**
     * @brief Sets the command trie for the CommandLineEdit.
     * @param newCommandTrie The new command trie to be set.
     */
    void setCommandTrie(const std::shared_ptr<CommandTrieNode> &newCommandTrie);

protected:

    /**
     * @brief Overrides the keyPressEvent for custom key handling.
     * @param event The key event.
     *          implements commands on enter and tab completion using trie
     */
    void keyPressEvent(QKeyEvent *event) override;

private:
    std::shared_ptr<CommandTrieNode> commandTrie; /**< The command trie associated with this CommandLineEdit. */

};

/**
 * @class TextGameView
 * @brief Manages the text-based game view by inheriting from GameView.
 */
class TextGameView: public GameView
{
public:

    /**
     * @brief Constructor for TextGameView.
     * @param mw Reference to the MainWindow object.
     */
    TextGameView(MainWindow& mw) : GameView(mw){};

    /**
     * @brief Initializes the main window for the text-based game view.
     * Sets up necessary elements like text areas, labels, and commands.
     */
    void initializeMainWindow() override;

    /**
     * @brief Clears the main window, removing text and UI elements.
     */
    void clearMainWindow() override;


private:
    std::shared_ptr<QPlainTextEdit> textEdit; /**< Text area to display game information. */
    std::shared_ptr<QLabel> availableCommandsTextLabel; /**< Label to display available commands. */
    std::shared_ptr<QLabel> healthLabel; /**< Label for health information. */
    std::shared_ptr<QLabel> healthValueLabel; /**< Label for health value. */
    std::shared_ptr<QLabel> energyLabel; /**< Label for energy information. */
    std::shared_ptr<QLabel> energyValueLabel; /**< Label for energy value. */
    std::shared_ptr<CommandLineEdit> lineEdit; /**< Line edit widget for user input. */
    std::shared_ptr<CommandTrieNode> commandTrie; /**< Command trie to handle user commands. */

    /**
     * @brief Sets up basic commands for the text-based game view.
     * Includes movement commands, help, and view switching. Adds these commands into the trie structure
     */
    void setupBasicCommands();///ADD A PUBLIC FUNCTION TO ADD MORE

};

#endif // TEXTGAMEVIEW_H
