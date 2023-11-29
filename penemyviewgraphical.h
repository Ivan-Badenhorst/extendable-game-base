#ifndef PENEMYVIEWGRAPHICAL_H
#define PENEMYVIEWGRAPHICAL_H
#include <memory>
#include "enemyviewinterface.h"
#include "penemymodel.h"


class PEnemyViewGraphical: public EnemyViewInterface
{
public:
    PEnemyViewGraphical();
    void update() override;
    void clearView() override;
    //void update(int row, int col, bool used = true) override;

    void setPenemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel);

private:
    std::shared_ptr<PEnemyModel> penemyModel;

    float zValue {1};
    int tileDim {50};

    std::vector<std::shared_ptr<QGraphicsPixmapItem>> penemyDisplays;
    void displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y);
};

#endif // PENEMYVIEWGRAPHICAL_H
