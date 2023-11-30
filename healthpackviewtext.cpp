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

    int moveDown = 1 + 2*row;
    int moveRight = 2 + 4*col;

    auto cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.clearSelection();

    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, moveDown);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);

    cursor.deleteChar();
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
