#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
#include "enemyviewinterface.h"
#include "penemymodel.h"
#include <memory>


class EnemyController
{
public:
    EnemyController();
    void refreshAllGraphical();
    //bool update(int row, int col);//row and col are tile numbers
    void addEnemyModel(std::shared_ptr<EnemyModelInterface> em);


    void setEnemyView(const std::vector<std::shared_ptr<EnemyViewInterface> > &newEnemyView);

    std::vector<std::shared_ptr<EnemyModelInterface> > getAllEnemyModels() const;
    std::shared_ptr<EnemyModel> getEnemyModel() const;
    std::shared_ptr<PEnemyModel> getPEnemyModel() const;

private:
    std::vector<std::shared_ptr<EnemyModelInterface>> enemyModels;
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews;
};

#endif // ENEMYCONTROLLER_H
