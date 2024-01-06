#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController( std::shared_ptr<ProtagonistModel> pm)
    :protModel(pm)
{
    connect(&attackTimer, &QTimer::timeout, this, &ProtagonistController::onAttackTimerTimeout);
    connect(&healthGainTimer, &QTimer::timeout, this, &ProtagonistController::onHealthGainTimerTimeout);
    connect(&deathTimer, &QTimer::timeout, this, &ProtagonistController::onDeathTimerTimeout);
    connect(&takeDamageTimer, &QTimer::timeout, this, &ProtagonistController::onDamageTimerTimeout);
}

void ProtagonistController::refreshAll()
{
    protView->update();
}

void ProtagonistController::update(int row, int col)
{
    protView->update(row, col);
    protModel->updatePosition(row, col);
}

void ProtagonistController::gainHealth(int hpValue)
{
    protModel->updateHealth(hpValue);
    protView->updateHealth();
    currentFrame = 0;


    healthGainTimer.setInterval(200);
    healthGainTimer.start();
}

bool ProtagonistController::takeDamage(int hpValue)
{
    isDead = protModel->updateHealth(-hpValue);
    protView->updateHealth();
    takeDamageTimer.setInterval(300);
    takeDamageTimer.start();
    return isDead;
}

void ProtagonistController::attackEnemy()
{
    attackTimer.setInterval(200);
    attackTimer.start();
}

int ProtagonistController::getAttackDamage()
{
    return protModel->getAttackDamage();
}

bool ProtagonistController::updateEnergy(float enValue)
{
    isDead = protModel->updateEnergy(-enValue);
    protView->updateEnergy();
    return isDead;
}

void ProtagonistController::updateWarning(bool isInDanger)
{
    protModel->setInDangerZone(isInDanger);
}

void ProtagonistController::showDeath()
{
    currentFrame = 0;

    deathTimer.setInterval(450); // Adjust interval for each frame
    deathTimer.start();

}

bool ProtagonistController::getIsDead() const
{
    return isDead;
}

void ProtagonistController::setProtView(const std::shared_ptr<ProtagonistView> &newProtView)
{
    protView = newProtView;
}

std::shared_ptr<ProtagonistModel> ProtagonistController::getProtModel() const
{
    return protModel;
}

void ProtagonistController::onAttackTimerTimeout()
{

    protView->performAttack(currentFrame);
    if (forwardAnimation) {
        if (currentFrame < 3) {
            ++currentFrame;
        } else {
            forwardAnimation = false;
            currentFrame = 2;
        }
    } else { //reverse sequence
        if (currentFrame > 0) {
            --currentFrame;
        }else{
            attackTimer.stop();
            forwardAnimation = true;
        }

    }

}

void ProtagonistController::onHealthGainTimerTimeout()
{

    if (currentFrame % 2 == 0) {
        protView->performHealthGain(0); // Display the 'prisoner_health' frame
    } else {
        protView->performHealthGain(1); // Display the 'prisoner_0' frame
    }


    ++currentFrame;
    if (currentFrame > 3) {
        healthGainTimer.stop();
        currentFrame = 0; // Reset the frame count for future iterations
    }

}

void ProtagonistController::onDeathTimerTimeout()
{
    protView->performDeath(currentFrame);
    ++currentFrame;
    if (currentFrame > 4) {
        deathTimer.stop();
        currentFrame = 0; // Reset the frame count for future iterations
    }

}

void ProtagonistController::onDamageTimerTimeout()
{
    if (currentFrame % 2 == 0) {
        protView->performTakeDamage(0); // Display the 'prisoner_health' frame
    } else {
        protView->performTakeDamage(1); // Display the 'prisoner_0' frame
    }


    ++currentFrame;
    if (currentFrame > 3) {
        takeDamageTimer.stop();
        currentFrame = 0; // Reset the frame count for future iterations
    }

}
