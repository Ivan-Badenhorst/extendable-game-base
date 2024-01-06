/**
 * @file PEnemyViewText.h
 * @brief Text-based representation of P-type enemies in a game environment.
 *
 * This class extends BaseEnemyView and implements PEnemyView, providing
 * a text-based representation for P-type enemies. It manages rendering individual
 * PEnemies and updating the view based on the PEnemyModel in a textual format.
 */

#ifndef PENEMYVIEWTEXT_H
#define PENEMYVIEWTEXT_H


#include "baseenemyview.h"
#include "penemymodel.h"
#include "penemyview.h"

/**
 * @class PEnemyViewText
 * @brief Text-based view class for P-type enemies in the game.
 *
 * PEnemyViewText is responsible for the text-based representation of P-type enemies on the screen.
 * It handles rendering of each PEnemy based on the state and information provided
 * by the PEnemyModel. This includes rendering individual PEnemies as well as updating
 * the entire view in a textual format.
 */
class PEnemyViewText: public BaseEnemyView, public PEnemyView
{
public:
    /**
     * @brief Constructor for PEnemyViewText.
     */
    PEnemyViewText();

    void render() override;
    void clearView() override;
    void render(int row, int col) override;
    void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel) override;

private:
    std::shared_ptr<PEnemyModel> penemyModel; ///< The PEnemyModel associated with this view.
};

#endif // PENEMYVIEWTEXT_H
