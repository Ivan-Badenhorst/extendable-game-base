#ifndef PROTAGONISTVIEW_H
#define PROTAGONISTVIEW_H

#include "protagonistmodel.h"
#include "qlabel.h"
class ProtagonistView
{
public:
    virtual void update() = 0;
    virtual void update(int row, int col) = 0;
    virtual void updateHealth() = 0;
    virtual void updateEnergy()=0;
    virtual void updateFrame(int currentFrame)= 0;
    virtual void clearView() = 0;
    virtual void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) = 0;

protected:
        std::shared_ptr<ProtagonistModel> protModel;
};


#endif
