#include "HealthPackH/healthpackcontroller.h"

HealthPackController::HealthPackController(std::shared_ptr<HealthPackView> hpv, std::shared_ptr<HealthPackModel> hpm)
    :hpView(hpv), hpModel(hpm)
{

}

void HealthPackController::refreshAll()
{

}
