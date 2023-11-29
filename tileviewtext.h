#ifndef TILEVIEWTEXT_H
#define TILEVIEWTEXT_H


#include "TileH/tileview.h"

class TileViewText: public TileView
{
public:
    TileViewText();
    void update(int row = 0, int col = 0) override;
    void clearView() override;
};

#endif // TILEVIEWTEXT_H
