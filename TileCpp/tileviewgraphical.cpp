#include "TileH/tileviewgraphical.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "ui_mainwindow.h"
#include "TileH/tilemodel.h"

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

    auto halfDisplayWidth = displayWidth / 2;
    auto halfDisplayHeight = displayHeight / 2;

    auto tileTable = tileModel->getTileTable();

    if(prevRow < 0 || prevCol < 0 || std::abs(positionRow-prevRow) > 1 || std::abs(positionCol - prevCol) > 1){
        displaySection(positionRow-halfDisplayHeight, positionRow+halfDisplayHeight, positionCol-halfDisplayWidth, positionCol+halfDisplayWidth);
    }
    else{//only display the new tiles
        if(positionRow > prevRow){//moved 1 row down
            int r = positionRow+halfDisplayHeight;
            displaySection(r, r, positionCol-halfDisplayWidth, positionCol+halfDisplayWidth);
        }
        else if(positionRow < prevRow){//moved 1 row up
            int r = positionRow-halfDisplayHeight;
            displaySection(r, r, positionCol-halfDisplayWidth, positionCol+halfDisplayWidth);
        }

        if(positionCol > prevCol){//moved 1 col right
            int r = positionCol+halfDisplayWidth;
            displaySection(positionRow-halfDisplayHeight, positionRow+halfDisplayHeight, r, r);
        }
        else if(positionCol < prevCol){
            int r = positionCol-halfDisplayWidth;
            displaySection(positionRow-halfDisplayHeight, positionRow+halfDisplayHeight, r, r);
        }
    }




    // Calculate the position to show
    auto  topLeftY = positionRow*tileDim - halfDisplayHeight*tileDim;
    auto topLeftX= positionCol*tileDim - halfDisplayWidth*tileDim;
    QRectF areaToShow = QRectF(topLeftX, topLeftY, tileDim*displayWidth, tileDim*displayHeight);


    mainWindow.getUi()->graphicsView->setSceneRect(areaToShow);

    prevCol = positionCol;
    prevRow = positionRow;
}

void TileViewGraphical::displaySection(int rowStart, int rowEnd, int colStart, int colEnd)
{
    auto tileTable = tileModel->getTileTable();

    for(int row = rowStart; row <= rowEnd; row++)
    {

        for (int col = colStart; col <= colEnd; col++ )
        {

            if(hasBeenRendered[row+(displayHeight/2)][col+(displayWidth/2)] == false){
//            if(hasBeenRendered[row][col] == false){
                auto rect = mainWindow.getScene()->addRect(col*tileDim,row*tileDim, tileDim, tileDim);

                int r = 0;
                int g = 0;
                int b = 0;

                if(row >= 0 && row < tileTable.size() && col >= 0 && col < tileTable[0].size()){
                    r = round(tileTable[row][col]*255);
                }

                QBrush brush(QColor(r,g,b));

                rect->setBrush(brush);
                rect->setZValue(0);

                hasBeenRendered[row+(displayHeight/2)][col+(displayWidth/2)] = true;
//                hasBeenRendered[row][col] = true;
//                std::cout << row <<";"<< col << std::endl;

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