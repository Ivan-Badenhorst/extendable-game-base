/**
 * @file graphicgameviewfactory.h
 * @brief Defines the GraphicGameViewFactory class.
 * Responsible for creating graphical game views by inheriting from GameViewFactory.
 */

#ifndef GRAPHICGAMEVIEWFACTORY_H
#define GRAPHICGAMEVIEWFACTORY_H

#include "gameviewfactory.h"

/**
 * @class GraphicGameViewFactory
 * @brief Responsible for creating graphical game views by inheriting from GameViewFactory.
 */
class GraphicGameViewFactory: public GameViewFactory
{
public:

    /**
     * @brief Default constructor for GraphicGameViewFactory.
     */
    GraphicGameViewFactory();

    /**
     * @brief Creates a graphical game view.
     * @param mainWindow Reference to the MainWindow object.
     * @return A unique pointer to the created game view.
     */
    std::unique_ptr<GameView> createView(MainWindow& mainWindow) override;
};

#endif // GRAPHICGAMEVIEWFACTORY_H
