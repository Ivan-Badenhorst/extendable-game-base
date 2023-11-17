#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "mainwindow.h"
#include "tilemodel.h"
#include "tileview.h"

#include <memory>

class TileViewGraphical: public TileView //refactor this -> we need a subclass for graphical view
{
public:
    TileViewGraphical(MainWindow& mw, std::shared_ptr<TileModel> tm);
    void update(int row = 0, int col = 0) override; //change this such that it only renders as the player walks!!!


private:
    MainWindow& mainWindow;
    std::shared_ptr<TileModel> tileModel;
    int prevRow {-1};
    int prevCol {-1};
};

#endif // TILEVIEWGRAPHICAL_H
