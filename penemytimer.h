#ifndef PENEMYTIMER_H
#define PENEMYTIMER_H

#include <QObject>
#include <memory>
#include <unordered_map>
#include <QTimer>
#include "enemycontroller.h"

class PEnemyTimer : public QObject
{
    Q_OBJECT
public:
    explicit PEnemyTimer(QObject *parent = nullptr);
    void setEnemyController(std::shared_ptr<EnemyController> ec);
    //void addEnemy(int x, int y);
private:
    std::shared_ptr<EnemyController> enemycontroller;
    QVector<QPointer<QTimer>> enemyTimers;
signals:
};

#endif // PENEMYTIMER_H
