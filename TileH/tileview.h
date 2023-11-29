#ifndef TILEVIEW_H
#define TILEVIEW_H

class TileView
{
public:
    virtual void update(int row = 0, int col = 0) = 0;
    virtual void clearView() = 0;
};


#endif // TILEVIEW_H
