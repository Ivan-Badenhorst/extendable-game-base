#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
#include "enemyviewinterface.h"
#include <memory>


class EnemyController
{
public:
    EnemyController();
    void refreshAllGraphical();
    //bool update(int row, int col);//row and col are tile numbers
    void addEnemyModel(std::shared_ptr<EnemyModelInterface> em);
    void addEnemyGraphicalView(std::shared_ptr<EnemyViewInterface> ev);

private:
    std::vector<std::shared_ptr<EnemyModelInterface>> enemyModels;
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyGraphicalViews;
};

#endif // ENEMYCONTROLLER_H
