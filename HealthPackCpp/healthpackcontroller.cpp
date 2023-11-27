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
    int hpValue = hpModel->containsHp(row, col);
    if(hpValue > 0) hpView->update(row,col);
    return hpValue;
}
