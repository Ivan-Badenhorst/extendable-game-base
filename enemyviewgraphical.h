#ifndef ENEMYVIEWGRAPHICAL_H
#define ENEMYVIEWGRAPHICAL_H
#include <memory>
#include <unordered_set>
#include "enemyview.h"
#include "enemyviewinterface.h"
#include "enemymodel.h"
#include "mainwindow.h"



class EnemyViewGraphical: public EnemyViewInterface, public EnemyView
{
public:
    EnemyViewGraphical();

    /***
     * @brief render
     * This method renders all Enemies in the EnemyModel.
    */
    void render() override;

    /***
     * @brief render
     * This method renders a single Enemy in the EnemyModel.
     * @param row
     * @param col
    */
    void render(int x, int y) override;

    void clearView() override;
    //void update(int row, int col, bool used = true) override;

    void setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel) override;

    private:
        std::shared_ptr<EnemyModel> enemyModel;

        float zValue {1};
        int tileDim {50};

        std::map<std::pair<int, int>, std::shared_ptr<QGraphicsPixmapItem>> enemiesDisplayed;
        void displayEnemy(int x, int y, bool defeated);
};

#endif // ENEMYVIEWGRAPHICAL_H
