#ifndef TILEVIEWTEXT_H
#define TILEVIEWTEXT_H


#include "TileH/tilemodel.h"
#include "TileH/tileview.h"
#include <memory>

class TileViewText: public TileView
{
public:
    TileViewText();
    void update(int row = 0, int col = 0) override;
    void clearView() override;
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel) override;

};

#endif // TILEVIEWTEXT_H
