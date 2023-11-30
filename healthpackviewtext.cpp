#include "healthpackviewtext.h"
#include "qtextcursor.h"
#include <iostream>


HealthPackViewText::HealthPackViewText()
{
//implement
}

void HealthPackViewText::update()
{
    for(auto& hp: hpModel->getHealthPacks()){

        if(hp[2]>0){//unused pack
            update(hp[0], hp[1], false);
        }
        else
        {
            update(hp[0], hp[1]);
        }

    }
}

void HealthPackViewText::update(int row, int col, bool used)
{



    int moveDown = 1 + 3*row;   // Number of lines to move down
    int moveRight = 2 + 5*col;  // Number of characters to move to the right

    auto cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.insertText("h");
    cursor.insertText("h");


    ///REPLACE THE FOR LOOP!!! FUNCTION CAN TAKE 3 PARAMETERS HEHE
    // Move the cursor down by 'moveDown' lines
    for (int i = 0; i < moveDown; ++i) {
        cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
    }

    // Move the cursor to the right by 'moveRight' characters
    for (int i = 0; i < moveRight; ++i) {
        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor);
    }

    // Set the new cursor position
    textEdit->setTextCursor(cursor);

    // Replace the character at the new cursor position
    if (cursor.hasSelection()) {
        // If there is a selection, replace the selected text
        cursor.removeSelectedText();
    }

    if(used) {cursor.insertText("h");}
    else {cursor.insertText("H");}

}

void HealthPackViewText::clearView()
{
    textEdit.reset();
}

void HealthPackViewText::setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel)
{
    hpModel = newHpModel;
}

void HealthPackViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}
