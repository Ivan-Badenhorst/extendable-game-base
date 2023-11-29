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
}

void ProtagonistController::addHealth(int hpValue)
{
    protModel->addHealth(hpValue);
    protView->updateHealth();
}

void ProtagonistController::setProtView(const std::shared_ptr<ProtagonistView> &newProtView)
{
    protView = newProtView;
}

std::shared_ptr<ProtagonistModel> ProtagonistController::getProtModel() const
{
    return protModel;
}
