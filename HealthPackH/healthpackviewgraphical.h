#ifndef HEALTHPACKVIEWGRAPHICAL_H
#define HEALTHPACKVIEWGRAPHICAL_H

#include <memory>

#include "HealthPackH/healthpackview.h"
#include "HealthPackH/healthpackmodel.h"
#include "mainwindow.h"


class HealthPackViewGraphical: public HealthPackView
{
public:
    HealthPackViewGraphical(MainWindow& mw, std::shared_ptr<HealthPackModel> hpm);
    void update() override;

private:
    MainWindow& mainWindow;
    std::shared_ptr<HealthPackModel> hpModel;
};

#endif // HEALTHPACKVIEWGRAPHICAL_H
