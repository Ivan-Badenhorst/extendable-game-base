/**
 * @file PEnemyView.h
 * @brief Interface for the visual representation of P-type enemies in a game environment.
 *
 * This class defines the interface for PEnemy views. It provides the functionality
 * to set the model associated with the PEnemy view. Implementations of this class
 * should provide specific rendering and display logic for P-type enemies.
 */

#ifndef PENEMYVIEW_H
#define PENEMYVIEW_H
#include "penemymodel.h"

/**
 * @class PEnemyView
 * @brief Interface class for views of P-type enemies in the game.
 *
 * Defines the interface for views related to P-type enemies in the game. It requires
 * the implementation of setting a PEnemy model. The actual rendering and visual
 * representation of P-type enemies is to be defined in the subclasses.
 */
class PEnemyView
{
public:
    /**
     * @brief Sets the PEnemy model associated with this view.
     * 
     * This method links a PEnemyModel to the view, enabling the view to represent
     * the state and behavior of P-type enemies visually.
     * 
     * @param newEnemyModel Shared pointer to the PEnemyModel to be associated with this view.
     */
    virtual void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newEnemyModel) = 0;
    
private:

};
#endif // PENEMYVIEW_H
