#ifndef ENEMYVIEWINTERFACE_H
#define ENEMYVIEWINTERFACE_H

#include "enemymodel.h"
#include "qgraphicsscene.h"
#include <memory>
class EnemyViewInterface
{
public:
    virtual void update() = 0;

    virtual void update(int row, int col,  bool defeated) = 0;
    std::string getEnemyType() const;
    void setEnemyType(const std::string &value);

    virtual void clearView() = 0;


    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

protected:
    std::shared_ptr<QGraphicsScene> scene;
    std::string enemyType; // Protected string attribute for enemy type
};

inline void EnemyViewInterface::setScene(const std::shared_ptr<QGraphicsScene> &newScene)
{
    scene = newScene;
}

inline std::string EnemyViewInterface::getEnemyType() const
{
    return enemyType;
}

inline void EnemyViewInterface::setEnemyType(const std::string &value)
{
    enemyType = value;
}

#endif // ENEMYVIEWINTERFACE_H
