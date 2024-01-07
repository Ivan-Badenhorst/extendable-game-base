/**
 * @file gameview.h
 * @brief Manages various views within the game environment.
 *
 * This file contains the declaration of the GameView class, responsible
 * for managing and handling different views, such as enemy, tile, health pack,
 * and protagonist views within the game environment.
 */

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <memory>

#include "tileview.h"
#include "healthpackview.h"
#include "baseenemyview.h"
#include "protagonistview.h"
#include "mainwindow.h"

/**
 * @class GameView
 * @brief Manages the different views within the game environment.
 *
 * This class facilitates the handling and manipulation of various views
 * within the game, including enemy, tile, health pack, and protagonist views.
 */
class GameView
{
public:

    /**
     * @brief Constructs a GameView instance.
     * @param mw Reference to the main window of the game.
     */
    GameView(MainWindow& mw);

    /**
     * @brief Initializes the main window UI for the view.
     *
     * This virtual function is to be implemented by subclasses to create
     * the necessary user interface elements needed for this specific view.
     */
    virtual void initializeMainWindow() = 0;

    /**
     * @brief Clears the main window UI for the view.
     *
     * This virtual function is to be implemented by subclasses to clear
     * the UI elements associated with this view from the main window.
     */
    virtual void clearMainWindow() = 0;

protected:
    MainWindow& mainWindow; /**< Reference to the main window of the game. */
///View attributes, getters and setters:

public:

    /**
     * @brief Retrieves the vector of enemy views.
     * @return A vector of shared pointers to BaseEnemyView objects.
     */
    std::vector<std::shared_ptr<BaseEnemyView>>getEnemyView() const;

    /**
     * @brief Sets the vector of enemy views.
     * @param newEnemyView A vector of shared pointers to BaseEnemyView objects.
     */
    void setEnemyView(std::vector<std::shared_ptr<BaseEnemyView>> newEnemyView);

    /**
     * @brief Retrieves the tile view.
     * @return Shared pointer to the TileView object.
     */
    std::shared_ptr<TileView>getTileView() const;

    /**
     * @brief Sets the tile view.
     * @param newTileView Shared pointer to the TileView object.
     */
    void setTileView(std::shared_ptr<TileView> newTileView);

    /**
     * @brief Retrieves the health pack view.
     * @return Shared pointer to the HealthPackView object.
     */
    std::shared_ptr<HealthPackView>getHpView() const;

    /**
     * @brief Sets the health pack view.
     * @param newHpView Shared pointer to the HealthPackView object.
     */
    void setHpView(std::shared_ptr<HealthPackView> newHpView);

    /**
     * @brief Retrieves the protagonist view.
     * @return Shared pointer to the ProtagonistView object.
     */
    std::shared_ptr<ProtagonistView>getProtView() const;

    /**
     * @brief Sets the protagonist view.
     * @param newProtView Shared pointer to the ProtagonistView object.
     */
    void setProtView(std::shared_ptr<ProtagonistView> newProtView);

protected:
    std::vector<std::shared_ptr<BaseEnemyView>> enemyView; /**< Vector of shared pointers to enemy views. */
    std::shared_ptr<TileView> tileView; /**< Shared pointer to the tile view. */
    std::shared_ptr<HealthPackView> hpView; /**< Shared pointer to the health pack view. */
    std::shared_ptr<ProtagonistView> protView; /**< Shared pointer to the protagonist view. */
};

#endif // GAMEVIEW_H
