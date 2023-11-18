#ifndef HEALTHPACKCONTROLLER_H
#define HEALTHPACKCONTROLLER_H

#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackview.h"

class HealthPackController
{
public:
    HealthPackController(std::shared_ptr<HealthPackView> hpv, std::shared_ptr<HealthPackModel> hpm);
    void refreshAll();
    //add an update method!! See model for more details

private:
    std::shared_ptr<HealthPackView> hpView;
    std::shared_ptr<HealthPackModel> hpModel;

};

#endif // HEALTHPACKCONTROLLER_H
