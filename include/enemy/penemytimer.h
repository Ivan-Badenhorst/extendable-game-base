#ifndef PENEMYTIMER_H
#define PENEMYTIMER_H

#include <QObject>
#include <QVariant>
#include <QVector>
#include <QPointer>
#include <memory>
#include <QTimer>
#include <iostream>
#include <QRandomGenerator>

// Minimum and maximum time for the timer
#define MIN_TIME 15
#define MAX_TIME 2000

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
