#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController(std::shared_ptr<ProtagonistView> pv, std::shared_ptr<ProtagonistModel> pm)
    : protView(pv), protModel(pm)
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
}
