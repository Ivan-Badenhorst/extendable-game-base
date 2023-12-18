#include "penemytimer.h"

PEnemyTimer::PEnemyTimer(QObject *parent)
: QObject(parent)
{
    // Initialize the unordered map attribute
}


void PEnemyTimer::setEnemyController(std::shared_ptr<EnemyController> ec)
{
    enemycontroller = ec;
}

    


// void addEnemy(int x, int y){

// }
        
     
