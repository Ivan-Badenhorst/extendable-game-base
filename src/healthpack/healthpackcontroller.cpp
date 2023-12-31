#include "healthpackcontroller.h"

#include <iostream>

HealthPackController::HealthPackController(std::shared_ptr<HealthPackModel> hpm)
    :hpModel(hpm)
{

}

void HealthPackController::refreshAll()
{
    hpView->update();
}

int HealthPackController::update(int row, int col)
{
    int hpValue = hpModel->containsHp(row, col);
    if(hpValue != 0) hpView->update(row,col);
    return hpValue;
}

void HealthPackController::setHpView(const std::shared_ptr<HealthPackView> &newHpView)
{
    hpView = newHpView;
}

std::shared_ptr<HealthPackModel> HealthPackController::getHpModel() const
{
    return hpModel;
}
