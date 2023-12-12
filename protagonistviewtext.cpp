#include "protagonistviewtext.h"
#include <iostream>
#include <QTextBlock>

ProtagonistViewText::ProtagonistViewText()
{

}

void ProtagonistViewText::update()
{
    auto xPos = protModel->getPositionX();
    auto yPos = protModel->getPositionY();


    update(xPos,yPos);
    updateHealth();

}

void ProtagonistViewText::update(int row, int col)
{
//    int moveDown = row>0 ? 1 + 2*row: row + 1;
//    int moveRight = 2 + 4*col;


//    // Get the block at the desired line number (moveDown)
//    QTextBlock block = textEdit->document()->findBlockByLineNumber(moveDown);


//    auto cursor = textEdit->textCursor();

//    erasePreviousPosition(cursor, row);
//    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
//    cursor.clearSelection();
//    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, moveDown);
//    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);

//    cursor.deleteChar();
//    cursor.insertText("P");

///////////////////////////////////////////////////////////////////////////////////////
//    QTextCursor cursor = textEdit->textCursor();
//    cursor.movePosition(QTextCursor::Start);

//    QTextBlock block = textEdit->document()->findBlockByLineNumber(moveDown);

//    if (block.isValid()) {
//        cursor = QTextCursor(block);
//        cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);

//        if (cursor.position() < block.position() + block.length()) {
//            cursor.deleteChar();
//            cursor.insertText("P");
//        }

//    }
//////////////////////////////////////////////////////////////////////////////////////


    int newMoveDown = row > 0 ? 1 + 2 * row : row + 1;
    int newMoveRight = 2 + 4 * col;

    QTextCursor cursor = textEdit->textCursor();
    QTextBlock newBlock = textEdit->document()->findBlockByLineNumber(newMoveDown);


    if (newBlock.isValid()) {
        // Update the new position
        QTextCursor newCursor(newBlock);
        newCursor.movePosition(QTextCursor::StartOfBlock);
        while (newCursor.positionInBlock() < newMoveRight) {
            newCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor);
        }
        if (newCursor.positionInBlock() == newMoveRight) {
            newCursor.deleteChar();
            newCursor.insertText("P");
        }
    }
    erasePreviousPosition();

}

void ProtagonistViewText::erasePreviousPosition() { //QTextCursor& cursor, int row

//    if(row == 0){
//        cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, 1);
//    }
//    cursor.deleteChar();
//    cursor.insertText(" ");
    int oldMoveDown = protModel->getPositionX() > 0 ? 1 + 2 * protModel->getPositionX() : protModel->getPositionX() + 1;
    int oldMoveRight = 2 + 4 * protModel->getPositionY();

    QTextBlock oldBlock = textEdit->document()->findBlockByLineNumber(oldMoveDown);
    QTextCursor oldCursor(oldBlock);
    oldCursor.movePosition(QTextCursor::StartOfBlock);
    oldCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, oldMoveRight);
    oldCursor.deleteChar();
    oldCursor.insertText(" ");
//    while (oldCursor.positionInBlock() < oldMoveRight) {
//        oldCursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor);
//    }
//    if (oldCursor.positionInBlock() == oldMoveRight) {
//        oldCursor.deleteChar();
//        oldCursor.insertText(" ");
//    }


}


void ProtagonistViewText::updateHealth()
{
    int health = protModel->getCurrentHealth();
    int maxHealth = protModel->getMaxhealth();
    healthValueLabel->setText(QString::number(health) + " / " + QString::number(maxHealth));
}



void ProtagonistViewText::clearView()
{
    textEdit.reset();
    //healthLabel.reset();
    healthValueLabel.reset();
}

void ProtagonistViewText::setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel)
{
    protModel = newProtModel;
}

void ProtagonistViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}

void ProtagonistViewText::setHealthLabels(std::shared_ptr<QLabel> healthValue) {
    healthValueLabel = healthValue;
}
