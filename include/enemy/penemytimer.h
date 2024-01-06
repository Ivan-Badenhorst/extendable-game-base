/**
 * @file PEnemyTimer.h
 * @brief Timer class for managing periodic actions of P-type enemies in a game environment.
 *
 * This class extends QObject and is responsible for managing timers related to P-type
 * enemies, triggering actions at specific intervals.
 */

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


/**
 * @class PEnemyTimer
 * @brief Timer class for P-type enemies in the game.
 *
 * PEnemyTimer is responsible for managing the timers associated with each P-type enemy.
 * It handles the creation, management, and triggering of timers to perform actions
 * at specified intervals.
 */
class PEnemyTimer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for PEnemyTimer.
     * @param ec Shared pointer to the EnemyController.
     */
    explicit PEnemyTimer(std::shared_ptr<EnemyController> ec);

    /**
     * @brief Adds a timer for a new P-type enemy at specified coordinates.
     * 
     * This method creates a new timer for a P-type enemy and starts it. The timer
     * will trigger periodic actions for the enemy located at the given coordinates.
     * 
     * @param x The x-coordinate of the P-type enemy.
     * @param y The y-coordinate of the P-type enemy.
     */
    void addEnemy(int x, int y);

private:
    std::shared_ptr<EnemyController> enemycontroller; /**< Shared pointer to the EnemyController. */
    QVector<QPointer<QTimer>> enemyTimers; /**< Vector of pointers to timers for each P-type enemy. */

signals:

private slots:
    /**
     * @brief Slot to handle timer timeouts.
     * 
     * This slot is called whenever a timer for a P-type enemy times out. It triggers
     * the necessary actions to be performed by the enemy controller.
     */
    void onTimerTimeout();

};

#endif // PENEMYTIMER_H
