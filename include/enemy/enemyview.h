/**
 * @file EnemyView.h
 * @brief Class for the visual representation of various types of enemies in a game environment.
 *
 * This class provides the functionality to associate an EnemyModel with a view. 
 * It serves as a part of the MVC architecture, responsible for the visual representation
 * of different types of enemies (Enemy, PEnemy, XEnemy) in the game.
 */

#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include "enemymodel.h"

/**
 * @class EnemyView
 * @brief Class for representing the view of enemies in the game.
 *
 * EnemyView serves as the view component in the MVC pattern for the enemies in the game.
 * It links with an EnemyModel to visually represent the state and behaviors of various
 * types of enemies. Specific rendering and display logic for each enemy type should be
 * implemented in this class or its subclasses.
 */
class EnemyView
{
public:
    /**
     * @brief Sets the enemy model associated with this view.
     * 
     * This method is used to connect an EnemyModel to this view. It allows the view to
     * visually represent the state and behavior of the enemies based on the model's data.
     * 
     * @param newEnemyModel Shared pointer to the EnemyModel to be associated with this view.
     */
    virtual void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) = 0;

private:

};


#endif // ENEMYVIEW_H
