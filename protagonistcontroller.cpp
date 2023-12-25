#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController( std::shared_ptr<ProtagonistModel> pm)
    :protModel(pm)
{
    connect(&attackTimer, &QTimer::timeout, this, &ProtagonistController::onAttackTimerTimeout);
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

bool ProtagonistController::updateHealth(int hpValue)
{
    isDead = protModel->updateHealth(hpValue);
    protView->updateHealth();
    return isDead;
}


void ProtagonistController::takeDamage(int hpValue)
{
    protModel->takeDamage(hpValue);
    protView->updateHealth();
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

    protView->updateFrame(currentFrame);
    if (forwardAnimation) {
        // Move to the next frame in the forward sequence
        if (currentFrame < 3) {
            ++currentFrame;
        } else {
            // If reached the end of forward sequence, switch to the reverse sequence
            forwardAnimation = false;
            currentFrame = 2; // Skip the last frame (3) in reverse sequence
        }
    } else {
        // Move to the next frame in the reverse sequence
        if (currentFrame > 0) {
            --currentFrame;
        }else{
            attackTimer.stop();
            forwardAnimation = true;
            return;
        }

    }
}
