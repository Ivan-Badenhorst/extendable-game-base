/**
 * @file EnemyViewText.h
 * @brief Text-based representation of enemies in a game environment.
 *
 * This class extends BaseEnemyView and implements EnemyView, providing
 * a text-based representation for enemies. It manages rendering individual
 * enemies and updating the view based on the EnemyModel in a textual format.
 */

#ifndef ENEMYVIEWTEXT_H
#define ENEMYVIEWTEXT_H


#include "enemymodel.h"
#include "enemyview.h"
#include "baseenemyview.h"

/**
 * @class EnemyViewText
 * @brief Text-based view class for enemies in the game.
 *
 * This class is responsible for the text-based representation of enemies on the screen.
 * It handles rendering of each enemy based on the state and information provided
 * by the EnemyModel. This includes rendering individual enemies as well as updating
 * the entire view in a textual format.
 */
class EnemyViewText: public BaseEnemyView, public EnemyView
{
public:
    /**
     * @brief Constructor for EnemyViewText.
     */
    EnemyViewText();

    void render() override;
    void clearView() override;
    void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) override;
    void render(int x, int y) override;

private:
    std::shared_ptr<EnemyModel> enemyModel; ///< The EnemyModel associated with this view.

};

#endif // ENEMYVIEWTEXT_H
