/**
 * @file GameViewFactory.cpp
 * @brief Implementation of the GameViewFactory class.
 * Defines the functionality to create different types of GameViews.
 */

#ifndef GAMEVIEWFACTORY_H
#define GAMEVIEWFACTORY_H

#include "gameview.h"

/**
 * @class GameViewFactory
 * @brief Abstract Factory class for creating GameView instances.
 * Provides an interface for creating different types of GameViews.
 */
class GameViewFactory
{
public:

    /**
     * @brief Constructs a GameViewFactory object.
     */
    GameViewFactory();

    /**
     * @brief Creates a specific type of GameView based on the MainWindow.
     * @param mainWindow Reference to the MainWindow object used for view creation.
     * @return Unique pointer to the created GameView.
     */
    virtual std::unique_ptr<GameView> createView(MainWindow& mainWindow) = 0;
};

#endif // GAMEVIEWFACTORY_H
