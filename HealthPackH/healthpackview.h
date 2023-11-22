#ifndef HEALTHPACKVIEW_H
#define HEALTHPACKVIEW_H

class HealthPackView
{
public:
    virtual void update() = 0;
    virtual void update(int row, int col,  bool used = true) = 0;
};

#endif // HEALTHPACKVIEW_H
