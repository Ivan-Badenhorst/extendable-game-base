#ifndef PROTAGONISTVIEW_H
#define PROTAGONISTVIEW_H

class ProtagonistView
{
public:
    virtual void update() = 0;
    virtual void update(int row, int col) = 0;
    virtual void updateHealth() = 0;
    virtual void clearView() = 0;
};


#endif
