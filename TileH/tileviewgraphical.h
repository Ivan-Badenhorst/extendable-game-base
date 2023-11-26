#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "mainwindow.h"
#include "tilemodel.h"
#include "tileview.h"

#include <memory>

class TileViewGraphical: public TileView
{
public:
    TileViewGraphical(MainWindow& mw, std::shared_ptr<TileModel> tm);
    void update(int row = 0, int col = 0) override;


private:
    MainWindow& mainWindow;
    std::shared_ptr<TileModel> tileModel;
    int prevRow {-1};
    int prevCol {-1};
    int tileDim {50};


    int displayWidth {16}; //in number of tiles
    int displayHeight {8}; //in number of tiles

    std::vector<std::vector<bool>> hasBeenRendered;
    void displaySection(int rowStart, int rowEnd, int colStart, int colEnd);
};

#endif // TILEVIEWGRAPHICAL_H
