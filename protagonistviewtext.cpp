#include "protagonistviewtext.h"
#include <iostream>

ProtagonistViewText::ProtagonistViewText()
{

}

void ProtagonistViewText::update()
{

}

void ProtagonistViewText::update(int row, int col)
{

}

void ProtagonistViewText::updateHealth()
{

}

void ProtagonistViewText::clearView()
{

}

void ProtagonistViewText::setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel)
{
    protModel = newProtModel;
}

void ProtagonistViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}
