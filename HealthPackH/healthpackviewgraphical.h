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
    //MAYBE SECOND ONE WITH LOCATION!!!

private:
    MainWindow& mainWindow;
    std::shared_ptr<HealthPackModel> hpModel;
    int tileDim {50};
    std::vector<std::shared_ptr<QGraphicsPixmapItem>> healthpackDisplays;
    void displayHp(std::shared_ptr<QGraphicsPixmapItem> icon);
};

#endif // HEALTHPACKVIEWGRAPHICAL_H
