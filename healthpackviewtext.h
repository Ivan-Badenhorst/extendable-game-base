#ifndef HEALTHPACKVIEWTEXT_H
#define HEALTHPACKVIEWTEXT_H


#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackview.h"
#include <memory>
class HealthPackViewText: public HealthPackView
{
public:
    HealthPackViewText(std::shared_ptr<HealthPackModel> hpm);
    void update() override;
    void update(int row, int col,  bool used = true) override;
    void clearView() override;
private:
    std::shared_ptr<HealthPackModel> hpModel;
};

#endif // HEALTHPACKVIEWTEXT_H
