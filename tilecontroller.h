#ifndef TILECONTROLLER_H
#define TILECONTROLLER_H

#include "tilemodel.h"
#include "tileviewgraphical.h"

class TileController
{
public:
    TileController(std::shared_ptr<TileViewGraphical> tv, std::shared_ptr<TileModel> tm);
    void update();//later this method takes the position -> or we have reference to the protag

    ///POSSIBLE FUTURE METHODS:
    //update model for new level
    //maybe a change in game mode -> like when you attack the way tiles are shown is different
    //update view -> text


private:
    std::shared_ptr<TileViewGraphical> tileView;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILECONTROLLER_H
