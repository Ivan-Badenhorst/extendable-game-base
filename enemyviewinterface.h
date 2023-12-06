#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "qgraphicsscene.h"
#include <memory>
class EnemyViewInterface
{
public:
    virtual void update() = 0;
    //virtual void update(int row, int col,  bool used = true) = 0;
    virtual std::string getEnemyType() const = 0;
    virtual void setEnemyType(const std::string &value) = 0;
    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

protected:
    std::shared_ptr<QGraphicsScene> scene;
    std::string enemyType; // Protected string attribute for enemy type
};

inline void EnemyViewInterface::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

#endif // ENEMYVIEWINTERFACE_H
