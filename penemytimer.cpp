#include "penemytimer.h"
#include "enemycontroller.h"

PEnemyTimer::PEnemyTimer(std::shared_ptr<EnemyController> ec)
: enemycontroller(ec)
{
    // Add 100 disabled QTimer to QVector that are ready to be used
    for (int i = 0; i < 100; ++i) {
        QTimer* timer = new QTimer(this); // 'this' sets the parent for automatic deletion
        timer->setInterval(1000); // Example: set interval, adjust as needed
        timer->setSingleShot(true); // If you want the timer to be single-shot

        // Set custom properties. Replace '0' with actual values if needed
        timer->setProperty("x", QVariant(0));
        timer->setProperty("y", QVariant(0));
        timer->setProperty("counter", QVariant(0));

        timer->stop(); // Ensure the timer is not running
        enemyTimers.append(QPointer<QTimer>(timer));
    }
}

void PEnemyTimer::onTimerTimeout() {
    QTimer* senderTimer = qobject_cast<QTimer*>(sender());
    if (!senderTimer) return; // Safety check

    int counter = senderTimer->property("counter").toInt();
    if (counter < 4) {
        // Increment the counter and call drainPEnemy
        senderTimer->setProperty("counter", counter + 1);

        int x = senderTimer->property("x").toInt();
        int y = senderTimer->property("y").toInt();
        if (enemycontroller) {
            enemycontroller->drainPEnemy(x, y);
        }
    } else {
        // Reset x, y, and counter; disable the timer
        senderTimer->setProperty("x", 0);
        senderTimer->setProperty("y", 0);
        senderTimer->setProperty("counter", 0);
        senderTimer->stop();
    }
}
    


void PEnemyTimer::addEnemy(int x, int y)
{
    std::cout << "Added Penemy at " << x << ", " << y << std::endl;
}


    
        
     
