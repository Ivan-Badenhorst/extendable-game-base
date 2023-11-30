#include "tileviewtext.h"

#include <iostream>

TileViewText::TileViewText()
{

}

void TileViewText::update(int row, int col)
{
    if(displayed) return;
    displayed = true;
    auto grid = tileModel->getTileTable();
    QString output;

    auto first = true;

    for (const auto& row : grid) {
        if(first){
            first = false;
            for (auto& v: row) {
                // Top line of the tile
                output += "+---";
            }
            output += "+\n";
        }

        for (auto& v : row) {
            // Left side and right side of the tile
            output += "|   ";
        }
        output += "|\n";

        for (auto& v: row) {
            // Bottom line of the tile
            output += "+---";
        }
        output += "+\n";
    }


    //update the position to work with the right location from row and col!!!
    textEdit->clear();
    textEdit->setPlainText(output);

    QTextCursor cursor = textEdit->textCursor();
    cursor.setPosition(50); // Set the position where you want to move the viewport
    textEdit->setTextCursor(cursor);
    textEdit->centerCursor();


}

void TileViewText::clearView()
{
    textEdit.reset();
}

void TileViewText::setTileModel(const std::shared_ptr<TileModel> &newTileModel)
{
    tileModel = newTileModel;
}

void TileViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}
