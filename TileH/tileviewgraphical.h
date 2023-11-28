#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "mainwindow.h"
#include "tilemodel.h"
#include "tileview.h"

#include <memory>

class TileViewGraphical: public TileView
{
public:
    TileViewGraphical(std::shared_ptr<TileModel> tm);
    void update(int row = 0, int col = 0) override;


    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

private:
    std::shared_ptr<TileModel> tileModel;
    int prevRow {-1};
    int prevCol {-1};
    int tileDim {50};


    int displayWidth {16}; //in number of tiles
    int displayHeight {8}; //in number of tiles

    std::vector<std::vector<bool>> hasBeenRendered;
    void displaySection(int rowStart, int rowEnd, int colStart, int colEnd);

    std::shared_ptr<QGraphicsScene> scene;

};

#endif // TILEVIEWGRAPHICAL_H
