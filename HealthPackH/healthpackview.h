#ifndef HEALTHPACKVIEW_H
#define HEALTHPACKVIEW_H

class HealthPackView
{
public:
    virtual void update() = 0;//maybe add position so we only rerender one hp? Maybe make it optional through OVERLOAD?
};

#endif // HEALTHPACKVIEW_H
