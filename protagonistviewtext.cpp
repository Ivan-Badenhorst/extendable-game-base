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
    int moveDown = row>0 ? 1 + 2*row: row+1;
    int moveRight = 2 + 4*col;

    auto cursor = textEdit->textCursor();
    erasePreviousPosition(cursor);


    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.clearSelection();
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, moveDown);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);

    cursor.deleteChar();
    cursor.insertText("P");

}

void ProtagonistViewText::erasePreviousPosition(QTextCursor& cursor) {

    cursor.deleteChar();
    cursor.insertText(" ");
}


void ProtagonistViewText::updateHealth()
{
    //yet to implement that
    int health = protModel->getCurrentHealth();
    int maxHealth = protModel->getMaxhealth();
    healthValueLabel->setText(QString::number(health) + " / " + QString::number(maxHealth));

}

void ProtagonistViewText::setHealthLabels(QLabel* health, QLabel* healthValue) {
    healthLabel = health;
    healthValueLabel = healthValue;
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

