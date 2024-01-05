#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "enemymodel.h"

#include <memory>
#include <QGraphicsScene>
#include <QTextCursor>
#include <QPlainTextEdit>
#include <QTextBlock>

/**
 * @brief The EnemyViewInterface class is an abstract class that defines the interface for rendering enemy views.
 */
class EnemyViewInterface {
public:
    
    /**
     * @brief Renders all enemies for this enemy type using data 
     * from the corresponding enemy model.
     */
    virtual void render() = 0;

    /**
     * @brief Renders a specific enemy for this enemy type using data 
     * from the corresponding enemy model.
     * @param row The row position of the enemy.
     * @param col The column position of the enemy.
     */
    virtual void render(int x, int y) = 0;

    /**
     * @brief Gets the enemy type.
     * @return The enemy type as a string.
     */
    std::string getEnemyType() const;

    /**
     * @brief Sets the enemy type.
     * @param value The enemy type to set.
     */
    void setEnemyType(const std::string &value);

    /**
     * @brief Clears the enemy view.
     */
    virtual void clearView() = 0;

    /**
     * @brief Sets the scene for rendering the enemy view.
     * @param newScene The new scene to set.
     */
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

protected:
    std::shared_ptr<QGraphicsScene> scene; /**< The graphics scene for rendering the enemy view. */
    std::string enemyType; /**< The type of the enemy. */
    std::shared_ptr<QPlainTextEdit> textEdit;
};

inline void EnemyViewInterface::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

inline void EnemyViewInterface::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}

inline std::string EnemyViewInterface::getEnemyType() const
{
    return enemyType;
}

inline void EnemyViewInterface::setEnemyType(const std::string &value)
{
    enemyType = value;
}

#endif // ENEMYVIEWINTERFACE_H
