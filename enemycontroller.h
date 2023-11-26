#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include "enemymodel.h"
//#include "enemyview.h"
#include <memory>


class EnemyController
{
public:
    EnemyController();
    //void refreshAll();
    //bool update(int row, int col);//row and col are tile numbers
    void addEnemyModel(std::shared_ptr<EnemyModelInterface> em);

private:
    std::vector<std::shared_ptr<EnemyModelInterface>> enemyModels;
    
};

#endif // ENEMYCONTROLLER_H
