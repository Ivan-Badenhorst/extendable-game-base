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
    protModel->updatePosition(row,col);
}

void ProtagonistController::addHealth(int hpValue)
{
    protModel->addHealth(hpValue);
    protView->updateHealth();
}

bool ProtagonistController::updateEnergy(float enValue)
{
    bool isDead = protModel->updateEnergy(-enValue);
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
