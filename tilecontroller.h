#ifndef TILECONTROLLER_H
#define TILECONTROLLER_H

#include "tilemodel.h"
#include "tileview.h"

class TileController
{
public:
    TileController(TileView& tv, TileModel& tm);
    void update();//later this method takes the position -> or we have reference to the protag

private:
    TileView& tileView;
    TileModel& tileModel;
};

#endif // TILECONTROLLER_H
