#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController( std::shared_ptr<ProtagonistModel> pm)
    :protModel(pm)
{
    connect(&attackTimer, &QTimer::timeout, this, &ProtagonistController::onAttackTimerTimeout);
    connect(&healthGainTimer, &QTimer::timeout, this, &ProtagonistController::onHealthGainTimerTimeout);
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

void ProtagonistController::attackEnemy()
{
    attackTimer.setInterval(200);
    attackTimer.start();
}

void ProtagonistController::updateHealth(int hpValue)
{
    isDead = protModel->updateHealth(hpValue);
    protView->updateHealth();
    currentFrame = 0;


    healthGainTimer.setInterval(200); // Adjust interval for each frame
    healthGainTimer.start();
}


bool ProtagonistController::takeDamage(int hpValue)
{
    isDead = protModel->updateHealth(-hpValue);
    protView->updateHealth();
    return isDead;
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



void ProtagonistController::setProtView(const std::shared_ptr<ProtagonistView> &newProtView)
{
    protView = newProtView;
}

std::shared_ptr<ProtagonistModel> ProtagonistController::getProtModel() const
{
    return protModel;
}

bool ProtagonistController::getIsDead() const
{
    return isDead;
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
        // Show the 'prisoner_0' frame for 500 ms (half a second)
        protView->performHealthGain(1); // Display the 'prisoner_0' frame
    }

    // Increment the frame count
    ++currentFrame;

    if (currentFrame > 3) {
        healthGainTimer.stop();
        currentFrame = 0; // Reset the frame count for future iterations
    }

}
