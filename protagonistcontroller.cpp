#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController( std::shared_ptr<ProtagonistModel> pm)
    :protModel(pm)
{

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
