#ifndef PENEMYVIEWGRAPHICAL_H
#define PENEMYVIEWGRAPHICAL_H
#include <memory>
#include "enemyviewinterface.h"
#include "penemymodel.h"
#include "mainwindow.h"

class PEnemyViewGraphical: public EnemyViewInterface
{
public:
    PEnemyViewGraphical(MainWindow& mw, std::shared_ptr<PEnemyModel> pem);
    void update() override;
    //void update(int row, int col, bool used = true) override;

private:
    MainWindow& mainWindow;
    std::shared_ptr<PEnemyModel> penemyModel;

    float zValue {1};
    int tileDim {50};

    std::vector<std::shared_ptr<QGraphicsPixmapItem>> penemyDisplays;
    void displayEnemy(std::shared_ptr<QGraphicsPixmapItem> icon, int x, int y);
};

#endif // PENEMYVIEWGRAPHICAL_H
