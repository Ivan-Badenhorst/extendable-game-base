#ifndef TILECONTROLLER_H
#define TILECONTROLLER_H

#include "tilemodel.h"
#include "tileview.h"

class TileController
{
public:
    TileController(std::shared_ptr<TileView> tv, std::shared_ptr<TileModel> tm);
    void update();//later this method takes the position -> or we have reference to the protag


private:
    std::shared_ptr<TileView> tileView;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILECONTROLLER_H
