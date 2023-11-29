#ifndef TILEVIEWTEXT_H
#define TILEVIEWTEXT_H


#include "TileH/tilemodel.h"
#include "TileH/tileview.h"
#include <memory>

class TileViewText: public TileView
{
public:
    TileViewText(std::shared_ptr<TileModel> tm);
    void update(int row = 0, int col = 0) override;
    void clearView() override;

private:
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILEVIEWTEXT_H
