#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "qgraphicsscene.h"
#include <memory>
class EnemyViewInterface
{
public:
    virtual void update() = 0;
    //virtual void update(int row, int col,  bool used = true) = 0;

    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

inline void EnemyViewInterface::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

#endif // ENEMYVIEWINTERFACE_H
