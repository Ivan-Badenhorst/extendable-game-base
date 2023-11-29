#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "enemymodel.h"
#include "qgraphicsscene.h"
#include <memory>
class EnemyViewInterface
{
public:
    virtual void update() = 0;
    virtual void clearView() = 0;

    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

inline void EnemyViewInterface::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

#endif // ENEMYVIEWINTERFACE_H
