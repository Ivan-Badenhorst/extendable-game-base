#ifndef PENEMYTIMER_H
#define PENEMYTIMER_H

#include <QObject>
#include <QVariant>
#include <QVector>
#include <QPointer>
#include <memory>
#include <QTimer>
#include <iostream>

class EnemyController;

class PEnemyTimer : public QObject
{
    Q_OBJECT
public:
    explicit PEnemyTimer(std::shared_ptr<EnemyController> ec);
    void addEnemy(int x, int y);
private:
    std::shared_ptr<EnemyController> enemycontroller;
    QVector<QPointer<QTimer>> enemyTimers;
signals:

private slots:
    void onTimerTimeout();

};

#endif // PENEMYTIMER_H
