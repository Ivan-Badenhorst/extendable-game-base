/**
 * @file textgameviewfactory.h
 * @brief Contains the declaration of the TextGameViewFactory class, responsible for creating text-based game views.
 */

#ifndef TEXTGAMEVIEWFACTORY_H
#define TEXTGAMEVIEWFACTORY_H

#include "gameviewfactory.h"

/**
 * @class TextGameViewFactory
 * @brief A factory class for generating text-based game views.
 *
 * This class implements the GameViewFactory interface to create various components
 * required for a text-based game view, including health packs, enemies, protagonists, tiles, etc.
 */
class TextGameViewFactory: public GameViewFactory
{
public:

    /**
     * @brief Constructor for TextGameViewFactory.
     */
    TextGameViewFactory();

    /**
     * @brief Creates a new instance of a text-based game view.
     * @param mainWindow The reference to the main window.
     * @return An instance of the text-based game view.
     */
    std::unique_ptr<GameView> createView(MainWindow& mainWindow) override;
};

#endif // TEXTGAMEVIEWFACTORY_H
