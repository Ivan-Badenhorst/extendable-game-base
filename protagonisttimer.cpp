#include "protagonisttimer.h"


protagonistTimer::protagonistTimer(std::shared_ptr<ProtagonistController> pc)
    : protController(pc)
{
    // Add a few disabled QTimer to QVector for attack animation
    for (int i = 0; i < 3; ++i) {
        auto attackTimer = new QTimer(this);
        attackTimer->setInterval(100); // Adjust interval as needed
        attackTimer->setSingleShot(true);

        attackTimer->stop(); // Ensure the timer is not running

        connect(attackTimer, &QTimer::timeout, this, &protagonistTimer::onAttackTimerTimeout);

        protTimers.append(QPointer<QTimer>(attackTimer));

    }
}

void protagonistTimer::startAttackAnimation()
{
    for (int i = 0; i < protTimers.size(); ++i) {
        protTimers[i]->start();
    }
}

void protagonistTimer::onAttackTimerTimeout()
{
        protController->handleAttackAnimation(currentFrame);

        // Move to the next frame or loop back to the first frame if reached the end
        currentFrame = (currentFrame + 1) % attackTimers.size();
    }
}
