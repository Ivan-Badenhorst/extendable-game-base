#ifndef HEALTHPACKVIEW_H
#define HEALTHPACKVIEW_H

#include "healthpackmodel.h"
class HealthPackView
{
public:
    virtual void update() = 0;
    virtual void update(int row, int col,  bool used = true) = 0;
    virtual void clearView() = 0;
    virtual void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) = 0;

protected:
    std::shared_ptr<HealthPackModel> hpModel;

};

#endif // HEALTHPACKVIEW_H
