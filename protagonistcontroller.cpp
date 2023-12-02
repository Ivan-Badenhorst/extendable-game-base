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

void ProtagonistController::addHealth(int hpValue)
{
    protModel->addHealth(hpValue);
    protView->updateHealth();
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

void ProtagonistController::setProtView(const std::shared_ptr<ProtagonistView> &newProtView)
{
    protView = newProtView;
}

std::shared_ptr<ProtagonistModel> ProtagonistController::getProtModel() const
{
    return protModel;
}
