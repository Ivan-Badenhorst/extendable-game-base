#include "protagonistviewtext.h"
#include <iostream>

ProtagonistViewText::ProtagonistViewText()
{

}

void ProtagonistViewText::update()
{
    auto xPos = protModel->getPositionX();
    auto yPos = protModel->getPositionY();


    update(xPos,yPos);

}

void ProtagonistViewText::update(int row, int col)
{
    int moveDown = 1 + 2*row;
    int moveRight = 2 + 4*col;

    auto cursor = textEdit->textCursor();
    erasePreviousPosition(cursor);
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.clearSelection();

    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, moveDown);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);
    // I need to store the H or h that was there before doing this or use something ivan did....
    cursor.deleteChar();
    cursor.insertText("P");

}

void ProtagonistViewText::erasePreviousPosition(QTextCursor& cursor) {

    //FIX THISSSS!!
    QString selectedText = cursor.selectedText();

    if( selectedText == 'H')
    {
        cursor.deleteChar();
        cursor.insertText("h");
    }
    else{
        cursor.deleteChar();
        cursor.insertText(" ");
    }

}


void ProtagonistViewText::updateHealth()
{
    //yet to implement that
}

void ProtagonistViewText::clearView()
{
    textEdit.reset();
}

void ProtagonistViewText::setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel)
{
    protModel = newProtModel;
}

void ProtagonistViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}
