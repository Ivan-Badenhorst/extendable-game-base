#ifndef HEALTHPACKVIEWTEXT_H
#define HEALTHPACKVIEWTEXT_H


#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackview.h"
#include <memory>
class HealthPackViewText: public HealthPackView
{
public:
    HealthPackViewText();
    void update() override;
    void update(int row, int col,  bool used = true) override;
    void clearView() override;
    void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) override;
};

#endif // HEALTHPACKVIEWTEXT_H
