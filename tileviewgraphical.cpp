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
    mainWindow.getUi()->graphicsView->setSceneRect(areaToShow);
}
