#include "tileviewgraphical.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "ui_mainwindow.h"
#include "tilemodel.h"

#include <iostream>
#include <cstdlib>

TileViewGraphical::TileViewGraphical(MainWindow& mw, std::shared_ptr<TileModel> tm)
    : mainWindow(mw), tileModel(tm)
{
    int tileRows =  tm->getRows()+ displayHeight;
    int tileCols = tm->getColumns() + displayWidth;
    hasBeenRendered.reserve(tileRows);


    for (int i = 0; i < tileRows; i++) {
        hasBeenRendered.emplace_back();
        hasBeenRendered.back().reserve(tileCols);
    }

    //set all to false -> nothing has been rendered yet
    for (size_t i = 0; i < tileRows; ++i) {
        for (size_t j = 0; j < tileCols; ++j) {
            hasBeenRendered[i].push_back(false);
        }
    }
}

void TileViewGraphical::update(int positionRow, int positionCol)
{

    auto tileTable = tileModel->getTileTable();

    //render entire display if we moved more than 2 squares, or if we are doing the initial display
    if(prevRow < 0 || prevCol < 0 || std::abs(positionRow-prevRow) > 1 || std::abs(positionCol - prevCol) > 1){
        displaySection(positionRow-displayHeight/2, positionRow+displayHeight/2, positionCol-displayWidth/2, positionCol+displayWidth/2);
    }
    else{//only display the new tiles
        if(positionRow > prevRow){//moved 1 row down
            int r = positionRow+displayHeight/2;
            displaySection(r, r, positionCol-displayWidth/2, positionCol+displayWidth/2);
        }
        else if(positionRow < prevRow){//moved 1 row up
            int r = positionRow-displayHeight/2;
            displaySection(r, r, positionCol-displayWidth/2, positionCol+displayWidth/2);
        }

        if(positionCol > prevCol){//moved 1 col right
            int r = positionCol+displayWidth/2;
            displaySection(positionRow-displayHeight/2, positionRow+displayHeight/2, r, r);
        }
        else if(positionCol < prevCol){
            int r = positionCol-displayWidth/2;
            displaySection(positionRow-displayHeight/2, positionRow+displayHeight/2, r, r);
        }
    }

    ///IDEAS FOR NOW:
    // save previous position so we know how we moved -> to know how to render
    /**
     * Possible mechanism:
     * keep a table same size as the map, where we remember what has been rendered
     * unless we don't care (if we can remove rectangles that have been rendered before!
     *
     */



//    displaySection(-4, 4, -8, 8);
//    displaySection(-4, 4, -8, 8);
    QRectF areaToShow = QRectF(positionRow-tileDim*displayWidth/2, positionCol-tileDim*displayHeight/2, tileDim*displayWidth, tileDim*displayHeight);
    mainWindow.getUi()->graphicsView->setSceneRect(areaToShow);
}

void TileViewGraphical::displaySection(int rowStart, int rowEnd, int colStart, int colEnd)
{
    auto tileTable = tileModel->getTileTable();

    for(int row = rowStart; row <= rowEnd; row++)
    {

        for (int col = colStart; col <= colEnd; col++ )
        {

            if(hasBeenRendered[row+(displayHeight/2)][col+(displayWidth/2)] == false){

                auto rect = mainWindow.getScene()->addRect(col*tileDim,row*tileDim, tileDim, tileDim);

                int r = 0;
                int g = 0;
                int b = 0;


                if(row >= 0 && row < tileTable.size() && col >= 0 && col < tileTable[0].size()){
                    r = round(tileTable[row][col]*255);
                }

                QBrush brush(QColor(r,g,b));

                rect->setBrush(brush);

                hasBeenRendered[row+(displayHeight/2)][col+(displayWidth/2)] = true;

                std::cout << row <<";"<< col << std::endl;

            }


        }


    }

}


/**
 *
 * POSSIBLE CODE TO CLEAR SCENE IN CERTAIN AREA:
 * QGraphicsScene *scene = ui->graphicsView->scene(); // Replace this with your method of getting the scene

QRectF areaToClear = QRectF(x, y, width, height); // Replace x, y, width, and height with your coordinates

// Iterate over the items in the scene and remove those within the area
QList<QGraphicsItem*> itemsToRemove;
foreach (QGraphicsItem *item, scene->items(areaToClear)) {
    if (item->boundingRect().intersects(areaToClear)) {
        itemsToRemove.append(item);
    }
}

foreach (QGraphicsItem *item, itemsToRemove) {
    scene->removeItem(item);
    delete item; // Ensure proper memory management if the item is dynamically allocated
}

 *
 *
 *
*/
