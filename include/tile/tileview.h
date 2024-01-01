#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "tilemodel.h"
class TileView
{
public:
    virtual void update(int row = 0, int col = 0) = 0;
    virtual void clearView() = 0;
    virtual void setTileModel(const std::shared_ptr<TileModel> &newTileModel) = 0;

protected:
    std::shared_ptr<TileModel> tileModel;
};


#endif // TILEVIEW_H
