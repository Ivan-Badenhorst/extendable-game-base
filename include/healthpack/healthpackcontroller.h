#ifndef HEALTHPACKCONTROLLER_H
#define HEALTHPACKCONTROLLER_H

#include "healthpackmodel.h"
#include "healthpackview.h"



class HealthPackController
{
public:
    HealthPackController(std::shared_ptr<HealthPackModel> hpm);
    void refreshAll();
    int update(int row, int col);//row and col are tile numbers


    void setHpView(const std::shared_ptr<HealthPackView> &newHpView);

    std::shared_ptr<HealthPackModel> getHpModel() const;

private:
    std::shared_ptr<HealthPackView> hpView;
    std::shared_ptr<HealthPackModel> hpModel;

};

#endif // HEALTHPACKCONTROLLER_H
