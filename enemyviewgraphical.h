#ifndef ENEMYVIEWGRAPHICAL_H
#define ENEMYVIEWGRAPHICAL_H
#include <memory>
#include "enemyviewinterface.h"
#include "enemymodel.h"
#include "mainwindow.h"

class EnemyViewGraphical: public EnemyViewInterface
{
public:
    EnemyViewGraphical(std::shared_ptr<EnemyModel> em);
    void update() override;
    void update(int row, int col, bool defeated) override;

private:
    std::shared_ptr<EnemyModel> enemyModel;

    float zValue {1};
    int tileDim {50};

    std::vector<std::shared_ptr<QGraphicsPixmapItem>> enemyDisplays;
    void displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y);
};

#endif // ENEMYVIEWGRAPHICAL_H
