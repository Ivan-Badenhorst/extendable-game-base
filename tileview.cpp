#include "tileview.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include <iostream>

TileView::TileView(MainWindow& mw, std::shared_ptr<TileModel> tm)
    : mainWindow(mw), tileModel(tm)
{

}

void TileView::update()
{
    std::cout << "start update" << std::endl;
    auto tileTable = tileModel->getTileTable();

    std::cout << "before for loop" << std::endl;
    for(int row = 0; row< tileTable.size(); row++)
    {
        std::cout << row << std::endl;

        for (int col = 0; col< tileTable[row].size(); col++ )
        {
            std::cout << col << std::endl;
            auto rect = mainWindow.getScene()->addRect(row*2,col*2, 2, 2);

            int colorval = round(tileTable[row][col]*255);
            QBrush *brush = new QBrush(QColor(colorval,0,0));
            rect->setBrush(*brush);

        }

    }
}
