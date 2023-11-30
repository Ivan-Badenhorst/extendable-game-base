#include "healthpackviewtext.h"
#include "qapplication.h"
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



    int moveDown = 1 + 2*row;   // Number of lines to move down
    int moveRight = 2 + 4*col;  // Number of characters to move to the right

    textEdit->setReadOnly(false);
    auto cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.clearSelection();




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
    cursor.deleteChar();


    if(used) {cursor.insertText("h");}
    else {cursor.insertText("H");}
    textEdit->repaint();

    textEdit->setTextCursor(cursor);
    textEdit->viewport()->update();
    QApplication::processEvents();
    textEdit->setReadOnly(true);


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
