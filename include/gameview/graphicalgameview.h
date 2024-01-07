/**
 * @file graphicalgameview.h
 * @brief Defines the GraphicalGameView class.
 * Provides a graphical representation of the game and defines needed components.
 */

#ifndef GRAPHICALGAMEVIEW_H
#define GRAPHICALGAMEVIEW_H

#include "gameview.h"
#include "qboxlayout.h"
#include <QProgressBar>


/**
 * @class HealthProgressBar
 * @brief Customized progress bar for health display.
 */
class HealthProgressBar : public QProgressBar {
public:
    explicit HealthProgressBar(QWidget *parent = nullptr) : QProgressBar(parent) {}

    QString text() const override {
        return QString("%1/%2 HP").arg(value()).arg(maximum());
    }
};

/**
 * @class EnergyProgressBar
 * @brief Customized progress bar for energy display.
 */
class EnergyProgressBar : public QProgressBar {
public:
    explicit EnergyProgressBar(QWidget *parent = nullptr) : QProgressBar(parent) {}

    QString text() const override {
        return QString("Energy: %1/%2 ").arg(value()).arg(maximum());
    }
};


/**
 * @class GraphicalGameView
 * @brief Represents a graphical view for the game.
 * Inherits from the GameView class and provides a graphical representation of the game.
 */
class GraphicalGameView: public GameView
{
public:
    /**
     * @brief Constructor for the GraphicalGameView.
     * @param mw Reference to the MainWindow object.
     */
    GraphicalGameView(MainWindow& mw) : GameView(mw){};

    /**
     * @brief Initializes the main window components for the graphical view.
     * Overrides the base class method to set up the graphical components.
     * Displays a graphics window, along with a energy and health bar
     */
    void initializeMainWindow() override;

    /**
     * @brief Clears the main window components.
     * Overrides the base class method to clear graphical components.
     */
    void clearMainWindow() override;

private:
    //main components
    std::shared_ptr<HealthProgressBar> healthBar; /**< Progress bar for health display. */
    std::shared_ptr<EnergyProgressBar> energyBar; /**< Progress bar for energy display. */
    std::shared_ptr<QGraphicsScene> scene; /**< Graphics scene for the game. */

    //supporting components
    std::shared_ptr<QGraphicsView> view; /**< Graphics view for the scene. */
    QWidget* widget; /**< Widget to hold the view. Memory managed by Qt. */
    QHBoxLayout* layout; /**< Horizontal layout for the bars. */
};

#endif // GRAPHICALGAMEVIEW_H
