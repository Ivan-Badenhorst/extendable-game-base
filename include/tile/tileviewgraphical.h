#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "qgraphicsscene.h"
#include "tilemodel.h"
#include "tileview.h"

#include <memory>

class TileViewGraphical: public TileView
{
public:
    TileViewGraphical();
    void update(int row = 0, int col = 0) override;
    void clearView() override;


    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

    void setTileModel(const std::shared_ptr<TileModel> &newTileModel) override;

private:
    int prevRow {-1};
    int prevCol {-1};
    int tileDim {50};


    int displayWidth {16}; //in number of tiles
    int displayHeight {8}; //in number of tiles

    bool portalsDisplayed {false};

    std::vector<std::vector<bool>> hasBeenRendered;
    void displaySection(int rowStart, int rowEnd, int colStart, int colEnd);

    std::shared_ptr<QGraphicsScene> scene;
    
    std::shared_ptr<QPixmap> getIcon(int range);
    std::vector<std::shared_ptr<QGraphicsPixmapItem>> tileDisplays;
    void AddPortalImage(int row, int col);
    void updateOpacityInRenderedArea();
};

#endif // TILEVIEWGRAPHICAL_H
