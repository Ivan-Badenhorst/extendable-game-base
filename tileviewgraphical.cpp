#include "tileviewgraphical.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "ui_mainwindow.h"

#include <iostream>

TileViewGraphical::TileViewGraphical(MainWindow& mw, std::shared_ptr<TileModel> tm)
    : mainWindow(mw), tileModel(tm)
{

}

void TileViewGraphical::update(int positionRow, int positionCol)
{

    auto tileTable = tileModel->getTileTable();


    //at the moment this displays all tiles!! I should only display the tiles around
    //the user!

    if(prevRow < 0 || prevCol < 0){
        std::cout << "full render" << std::endl;
    }
    else{
        std::cout << "no full render" << std::endl;
    }

    ///IDEAS FOR NOW:
    // save previous position so we know how we moved -> to know how to render
    /**
     * Possible mechanism:
     * keep a table same size as the map, where we remember what has been rendered
     * unless we don't care (if we can remove rectangles that have been rendered before!
     *
     */

    //write function that takes row start, row end, col start and col end to add the rectangles

//    for(int row = 0; row< tileTable.size(); row++)
//    {
//        std::cout << row << std::endl;

//        for (int col = 0; col< tileTable[row].size(); col++ )
//        {
//            auto rect = mainWindow.getScene()->addRect(row*tileDim,col*tileDim, tileDim, tileDim);

//            int colorval = round(tileTable[row][col]*255);
//            QBrush *brush = new QBrush(QColor(colorval,0,0));
//            rect->setBrush(*brush);

//        }

//    }

    displaySection(-8, 8, -4, 4);
    QRectF areaToShow = QRectF(positionRow-400, positionCol-200, 800, 400);


    //QRectF areaToShow = QRectF(positionRow, positionCol, 800, 400);
    mainWindow.getUi()->graphicsView->setSceneRect(areaToShow);
}

void TileViewGraphical::displaySection(int rowStart, int rowEnd, int colStart, int colEnd)
{
    auto tileTable = tileModel->getTileTable();

    for(int row = rowStart; row <= rowEnd; row++)
    {
        std::cout << row << std::endl;

        for (int col = colStart; col <= colEnd; col++ )
        {
            auto rect = mainWindow.getScene()->addRect(row*tileDim,col*tileDim, tileDim, tileDim);

            int r = 0;
            int g = 0;
            int b = 0;


            if(row >= 0 && row < tileTable.size() && col >= 0 && col < tileTable[0].size()){
                r = round(tileTable[row][col]*255);
            }

            QBrush brush(QColor(r,g,b));

            rect->setBrush(brush);

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
