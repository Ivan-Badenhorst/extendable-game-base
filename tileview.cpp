#include "tileview.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

TileView::TileView(MainWindow& mw, TileModel& tm)
    : mainWindow(mw), tileModel(tm)
{

}

void TileView::update()
{
    auto tileTable = tileModel.getTileTable();


    for(int row = 0; row< tileTable.size(); row++)
    {

        for (int col = 0; col< tileTable[row].size(); col++ )
        {
            //how do we get scene?
            auto rect = mainWindow.getScene()->addRect(row*2,col*2, 2, 2);

            int colorval = round(tileTable[row][col]*255);
            QBrush *brush = new QBrush(QColor(colorval,0,0));
            rect->setBrush(*brush);

        }

    }
}
