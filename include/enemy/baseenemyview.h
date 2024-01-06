/**
 * @file BaseEnemyView.h
 * @brief Abstract class for enemy views in a game world.
 *
 * Provides an abstract class for rendering enemy views in a game. This class
 * declares virtual methods for rendering, clearing, and managing the display
 * of enemies within the game world. It should be subclassed by specific
 * enemy view implementations.
 */

#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "enemymodel.h"

#include <memory>
#include <QGraphicsScene>
#include <QTextCursor>
#include <QPlainTextEdit>
#include <QTextBlock>

/**
 * @brief The BaseEnemyView class is an abstract class that defines the interface for rendering enemy views.
 */
class BaseEnemyView {
public:
    
    /**
     * @brief Renders all enemies for this enemy type.
     * 
     * Uses data from the corresponding enemy model to render all enemies of
     * a specific type.
     */
    virtual void render() = 0;

    /**
     * @brief Renders a specific enemy at the given coordinates.
     * 
     * @param x The x-coordinate position of the enemy.
     * @param y The y-coordinate position of the enemy.
     */
    virtual void render(int x, int y) = 0;

    /**
     * @brief Gets the enemy type.
     * 
     * @return The enemy type as a string.
     */
    std::string getEnemyType() const;

    /**
     * @brief Sets the enemy type.
     * 
     * @param value The enemy type to set.
     */
    void setEnemyType(const std::string &value);

    /**
     * @brief Clears the enemy view.
     * 
     * Removes all enemy renderings from the view.
     */
    virtual void clearView() = 0;

    /**
     * @brief Sets the graphics scene for rendering the enemy view.
     * 
     * @param newScene The new QGraphicsScene to set.
     */
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

    /**
     * @brief Sets the text edit for text-based game information display.
     * 
     * @param newTextEdit The new QPlainTextEdit to set.
     */
    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

protected:
    std::shared_ptr<QGraphicsScene> scene; /**< The graphics scene for rendering the enemy view. */
    std::string enemyType; /**< The type of the enemy. */
    std::shared_ptr<QPlainTextEdit> textEdit; /**< The text edit for displaying additional information. */
};

inline void BaseEnemyView::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

inline void BaseEnemyView::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}

inline std::string BaseEnemyView::getEnemyType() const
{
    return enemyType;
}

inline void BaseEnemyView::setEnemyType(const std::string &value)
{
    enemyType = value;
}

#endif // ENEMYVIEWINTERFACE_H
