#include "HealthPackH/healthpackcontroller.h"

HealthPackController::HealthPackController(std::shared_ptr<HealthPackView> hpv, std::shared_ptr<HealthPackModel> hpm)
    :hpView(hpv), hpModel(hpm)
{

}

void HealthPackController::refreshAll()
{
    hpView->update();
}

bool HealthPackController::update(int row, int col)
{
    bool contains = hpModel->containsHp(row, col);
    if(contains) hpView->update(row,col);
    return contains;
}
