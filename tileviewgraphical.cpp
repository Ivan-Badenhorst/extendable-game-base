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
    int tileDim = 50;

    //at the moment this displays all tiles!! I should only display the tiles around
    //the user!

    if(prevRow < 0 || prevCol < 0){
        std::cout << "full render" << std::endl;
    }
    else{
        std::cout << "no full render" << std::endl;
    }

    for(int row = 0; row< tileTable.size(); row++)
    {
        std::cout << row << std::endl;

        for (int col = 0; col< tileTable[row].size(); col++ )
        {
            auto rect = mainWindow.getScene()->addRect(row*tileDim,col*tileDim, tileDim, tileDim);

            int colorval = round(tileTable[row][col]*255);
            QBrush *brush = new QBrush(QColor(colorval,0,0));
            rect->setBrush(*brush);

        }

    }

    QRectF areaToShow = QRectF(0, 0, 800, 400);
//    mainWindow.getUi()->graphicsView->clearFocus();
    mainWindow.getUi()->graphicsView->setSceneRect(areaToShow);
}
