#include "HealthPackH/healthpackviewgraphical.h"

#include <iostream>

HealthPackViewGraphical::HealthPackViewGraphical(MainWindow &mw, std::shared_ptr<HealthPackModel> hpm)
    :mainWindow(mw), hpModel(hpm)
{

}

void HealthPackViewGraphical::update()
{

    for(auto& hp: hpModel->getHealthPacks()){

        std::cout << hp[2] << std::endl;

    }

}
