#ifndef TILECONTROLLER_H
#define TILECONTROLLER_H

#include "tilemodel.h"
#include "tileviewgraphical.h"

class TileController
{
public:
    TileController( std::shared_ptr<TileModel> tm);
    void update(int row = 0, int col = 0, bool allowPortal = true);//later this method takes the position -> or we have reference to the protag
    std::tuple<int, int> getDimensions();
    ///POSSIBLE FUTURE METHODS:
    //update model for new level
    //maybe a change in game mode -> like when you attack the way tiles are shown is different
    //update view -> text

    void addPortal(int row, int col, bool nextLevel);
    void setTileView(const std::shared_ptr<TileView> &newTileView);

    std::shared_ptr<TileModel> getTileModel() const;

private:
    std::shared_ptr<TileView> tileView;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILECONTROLLER_H
